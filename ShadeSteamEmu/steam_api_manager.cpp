#include "steam_api_manager.h"

#include <iostream>
#include <random>

#include "MinHook.h"
#include "steam/steam_api_common.h"
#include "steam_pointers.h"

const void* steam_api_manager::hooked_get_persona_name(void* instance_ptr)
{
    return jazz_man_name;
}

steam_api_manager::steam_api_manager()
{
    logfile_.open("steam_api_log.txt", std::ios_base::app);
    logfile_ << "Initializing steam api" << '\n';
    if (!function_pointers::initialize_function_pointers())
    {
        logfile_ << "Failed to initialize all pointers" << '\n';
    }
}

steam_api_manager::~steam_api_manager()
{
    if (function_pointers::steam_api_64_dll != nullptr)
    {
        FreeLibrary(function_pointers::steam_api_64_dll);
        logfile_.close();
    }
}

bool steam_api_manager::install_hook()
{
    // Initialize MinHook
    if (MH_Initialize() != MH_OK)
    {
        std::cerr << "Failed to initialize MinHook" << '\n';
        return false;
    }

    if (MH_CreateHook(reinterpret_cast<LPVOID>(function_pointers::get_persona_name_ptr), &hooked_get_persona_name,
                      nullptr) != MH_OK)
    {
        std::cerr << "Failed to create the hook for SteamAPI_ISteamFriends_GetPersonaName" << '\n';
        return false;
    }

    if (MH_EnableHook(reinterpret_cast<LPVOID>(function_pointers::get_persona_name_ptr)) != MH_OK)
    {
        std::cerr << "Failed to enable the hook for SteamAPI_ISteamFriends_GetPersonaName" << '\n';
        return false;
    }

    return true;
}

bool steam_api_manager::SteamAPI_Init()
{
    SetEnvironmentVariableA("SteamAppId", "480");
    return function_pointers::steam_init_ptr();
}

void* steam_api_manager::SteamAPI_GetHSteamUser()
{
    return function_pointers::hsteam_user_ptr();
}

void* steam_api_manager::SteamAPI_GetHSteamPipe()
{
    return function_pointers::hsteam_pipe_ptr();
}

void* steam_api_manager::SteamClient()
{
    return function_pointers::steam_client_ptr();
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamUser(void* steam_client_ptr,
                                                             void* hsteam_user_ptr,
                                                             void* hsteam_pipe_ptr,
                                                             const char* version)
{
    return function_pointers::steam_user_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamInternal_CreateInterface(const char* version)
{
    return function_pointers::create_interface_ptr(version);
}

void* steam_api_manager::SteamInternal_FindOrCreateUserInterface(void* hsteam_user_ptr, const char* psz_version)
{
    return function_pointers::steam_internal_findorcreateuserinterface_ptr(hsteam_user_ptr, psz_version);
}

void steam_api_manager::SteamAPI_ManualDispatch_Init()
{
    return function_pointers::steam_api_manualdispatch_init_ptr();
}

void steam_api_manager::SteamAPI_ISteamInput_EnableDeviceCallbacks(void* steam_input_ptr)
{
    return function_pointers::steam_api_enable_device_callbacks_ptr(steam_input_ptr);
}

bool steam_api_manager::SteamAPI_ISteamInput_Init(void* steam_input_ptr, bool b_explicitly_call_run_frame)
{
    return function_pointers::steam_api_input_init_ptr(steam_input_ptr, b_explicitly_call_run_frame);
}

bool steam_api_manager::SteamAPI_IsSteamRunning()
{
    return function_pointers::steam_api_is_steam_running_ptr();
}

bool steam_api_manager::SteamAPI_SteamNetworkingIdentity_SetGenericString(void* steam_network_identity,
                                                                          const char* psz_string)
{
    return function_pointers::steam_api_steam_networking_identity_set_generic_string_ptr(
        steam_network_identity, psz_string);
}

uint32_t steam_api_manager::SteamAPI_ISteamUser_GetAuthSessionTicket(void* steam_user,
                                                                     void* p_ticket,
                                                                     int cb_max_ticket,
                                                                     uint32_t* pcb_ticket,
                                                                     void* steam_network_identity)
{
    static const uint32_t max_ticket_size = 1024;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis_size(128, max_ticket_size);

    uint32_t ticket_size = dis_size(gen);
    if (cb_max_ticket >= static_cast<int>(ticket_size))
    {
        std::uniform_int_distribution<uint32_t> dis_byte(0, 255);
        uint8_t* ticket_data = reinterpret_cast<uint8_t*>(p_ticket);
        for (uint32_t i = 0; i < ticket_size; ++i)
        {
            ticket_data[i] = static_cast<uint8_t>(dis_byte(gen));
        }

        *pcb_ticket = ticket_size;
        return ticket_size;
    }
    else
    {
        *pcb_ticket = 0;
        return 0;
    }
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamApps(void* steam_client_ptr,
                                                             void* hsteam_user_ptr,
                                                             void* hsteam_pipe_ptr,
                                                             const char* version)
{
    return function_pointers::steam_apps_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamFriends(void* steam_client_ptr,
                                                                void* hsteam_user_ptr,
                                                                void* hsteam_pipe_ptr,
                                                                const char* version)
{
    return function_pointers::steam_friends_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamUtils(void* steam_client_ptr,
                                                              void* hsteam_pipe_ptr,
                                                              const char* version)
{
    return function_pointers::steam_utils_ptr(steam_client_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamMatchmaking(void* steam_client_ptr,
                                                                    void* hsteam_user_ptr,
                                                                    void* hsteam_pipe_ptr,
                                                                    const char* version)
{
    return function_pointers::steam_matchmaking_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamMatchmakingServers(void* steam_client_ptr,
                                                                           void* hsteam_user_ptr,
                                                                           void* hsteam_pipe_ptr,
                                                                           const char* version)
{
    return function_pointers::steam_match_making_servers_ptr(steam_client_ptr,
                                                             hsteam_user_ptr,
                                                             hsteam_pipe_ptr,
                                                             version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamUserStats(void* steam_client_ptr,
                                                                  void* hsteam_user_ptr,
                                                                  void* hsteam_pipe_ptr,
                                                                  const char* version)
{
    return function_pointers::steam_user_stats_ptr(steam_client_ptr,
                                                   hsteam_user_ptr,
                                                   hsteam_pipe_ptr,
                                                   version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamNetworking(void* steam_client_ptr,
                                                                   void* hsteam_user_ptr,
                                                                   void* hsteam_pipe_ptr,
                                                                   const char* version)
{
    return function_pointers::steam_networking_ptr(steam_client_ptr,
                                                   hsteam_user_ptr,
                                                   hsteam_pipe_ptr,
                                                   version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamRemoteStorage(void* steam_client_ptr,
                                                                      void* hsteam_user_ptr,
                                                                      void* hsteam_pipe_ptr,
                                                                      const char* version)
{
    return function_pointers::steam_remote_storage_ptr(steam_client_ptr,
                                                       hsteam_user_ptr,
                                                       hsteam_pipe_ptr,
                                                       version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamScreenshots(void* steam_client_ptr,
                                                                    void* hsteam_user_ptr,
                                                                    void* hsteam_pipe_ptr,
                                                                    const char* version)
{
    return function_pointers::steam_screen_shots_ptr(steam_client_ptr,
                                                     hsteam_user_ptr,
                                                     hsteam_pipe_ptr,
                                                     version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamGameSearch(void* steam_client_ptr,
                                                                   void* hsteam_user_ptr,
                                                                   void* hsteam_pipe_ptr,
                                                                   const char* version)
{
    return function_pointers::steam_game_search_ptr(steam_client_ptr,
                                                    hsteam_user_ptr,
                                                    hsteam_pipe_ptr,
                                                    version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamHTTP(void* steam_client_ptr,
                                                             void* hsteam_user_ptr,
                                                             void* hsteam_pipe_ptr,
                                                             const char* version)
{
    return function_pointers::steam_http_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamController(void* steam_client_ptr,
                                                                   void* hsteam_user_ptr,
                                                                   void* hsteam_pipe_ptr,
                                                                   const char* version)
{
    return function_pointers::steam_controller_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamUGC(void* steam_client_ptr,
                                                            void* hsteam_user_ptr,
                                                            void* hsteam_pipe_ptr,
                                                            const char* version)
{
    return function_pointers::steam_ugc_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamMusic(void* steam_client_ptr,
                                                              void* hsteam_user_ptr,
                                                              void* hsteam_pipe_ptr,
                                                              const char* version)
{
    return function_pointers::steam_music_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamMusicRemote(void* steam_client_ptr,
                                                                    void* hsteam_user_ptr,
                                                                    void* hsteam_pipe_ptr,
                                                                    const char* version)
{
    return function_pointers::steam_music_remote_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamHTMLSurface(void* steam_client_ptr,
                                                                    void* hsteam_user_ptr,
                                                                    void* hsteam_pipe_ptr,
                                                                    const char* version)
{
    return function_pointers::steam_htmlsurface_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamInventory(void* steam_client_ptr,
                                                                  void* hsteam_user_ptr,
                                                                  void* hsteam_pipe_ptr,
                                                                  const char* version)
{
    return function_pointers::steam_inventory_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamVideo(void* steam_client_ptr,
                                                              void* hsteam_user_ptr,
                                                              void* hsteam_pipe_ptr,
                                                              const char* version)
{
    return function_pointers::steam_video_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamParentalSettings(void* steam_client_ptr,
                                                                         void* hsteam_user_ptr,
                                                                         void* hsteam_pipe_ptr,
                                                                         const char* version)
{
    return function_pointers::steam_parentalsettings_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamInput(void* steam_client_ptr,
                                                              void* hsteam_user_ptr,
                                                              void* hsteam_pipe_ptr,
                                                              const char* version)
{
    return function_pointers::steam_input_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamParties(void* steam_client_ptr,
                                                                void* hsteam_user_ptr,
                                                                void* hsteam_pipe_ptr,
                                                                const char* version)
{
    return function_pointers::steam_parties_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamRemotePlay(void* steam_client_ptr,
                                                                   void* hsteam_user_ptr,
                                                                   void* hsteam_pipe_ptr,
                                                                   const char* version)
{
    return function_pointers::steam_remoteplay_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamClient_GetISteamAppList(void* steam_client_ptr,
                                                                void* hsteam_user_ptr,
                                                                void* hsteam_pipe_ptr,
                                                                const char* version)
{
    return function_pointers::steam_app_list_ptr(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr, version);
}

void* steam_api_manager::SteamAPI_ISteamFriends_GetPersonaName(void* steam_friends_ptr)
{
    return function_pointers::get_persona_name_ptr(steam_friends_ptr);
}

bool steam_api_manager::SteamAPI_ISteamApps_BIsSubscribedApp(void* steam_apps_ptr, const uint32 app_id)
{
    return function_pointers::is_subscribed_app_ptr(steam_apps_ptr, app_id);
}

bool steam_api_manager::SteamAPI_ISteamUser_BLoggedOn(void* steam_user_ptr)
{
    return function_pointers::blogged_ptr(steam_user_ptr);
}

void steam_api_manager::SteamAPI_Shutdown()
{
    function_pointers::steam_api_shutdown_ptr();
}

bool steam_api_manager::SteamAPI_ISteamUserStats_SetStatInt32(void* steam_user_stats, const char* pch_name,
                                                              int32_t ndata)
{
    return function_pointers::steam_api_user_stats_set_stat_int32_ptr(steam_user_stats, pch_name, ndata);
}

uint64_t steam_api_manager::SteamAPI_ISteamUser_GetSteamID(void* steam_user)
{
    return function_pointers::steam_api_user_get_steam_id_ptr(steam_user);
}

uint64_t steam_api_manager::SteamAPI_ISteamUserStats_RequestUserStats(void* steam_user_stats, uint64_t steamid_user)
{
    return function_pointers::steam_api_user_stats_request_user_stats_ptr(steam_user_stats, steamid_user);
}

bool steam_api_manager::SteamAPI_ISteamApps_BIsDlcInstalled(void* steam_apps, uint32_t app_id)
{
    return function_pointers::steam_api_apps_b_is_dlc_installed_ptr(steam_apps, app_id);
}

void steam_api_manager::SteamAPI_ManualDispatch_RunFrame(void* hsteampipe)
{
    function_pointers::steam_api_manual_dispatch_run_frame_ptr(hsteampipe);
}

bool steam_api_manager::SteamAPI_ManualDispatch_GetNextCallback(void* hsteampipe, void* p_callback_msg)
{
    return function_pointers::steam_api_manual_dispatch_get_next_callback_ptr(hsteampipe, p_callback_msg);
}

void steam_api_manager::SteamAPI_ManualDispatch_FreeLastCallback(void* hsteampipe)
{
    function_pointers::steam_api_manual_dispatch_free_last_callback_ptr(hsteampipe);
}

bool steam_api_manager::SteamAPI_ISteamRemoteStorage_FileExists(void* steam_remote_storage, const char* pch_file)
{
    return function_pointers::steam_api_remote_storage_file_exists_ptr(steam_remote_storage, pch_file);
}

int steam_api_manager::SteamAPI_ISteamInput_GetConnectedControllers(void* steam_input, uint64_t* handles_out)
{
    return function_pointers::steam_api_input_get_connected_controllers_ptr(steam_input, handles_out);
}

void steam_api_manager::SteamAPI_ISteamInput_RunFrame(void* steam_input, bool b_reserved_value)
{
    return function_pointers::steam_api_input_run_frame_ptr(steam_input, b_reserved_value);
}

bool steam_api_manager::SteamAPI_ISteamUserStats_GetStatFloat(void* steam_user_stats, const char* pch_name,
                                                              float* pdata)
{
    return function_pointers::steam_api_user_stats_get_stat_float_ptr(steam_user_stats, pch_name, pdata);
}

bool steam_api_manager::SteamAPI_ISteamUserStats_GetStatInt32(void* steam_user_stats, const char* pch_name,
                                                              int32_t* pdata)
{
    return function_pointers::steam_api_user_stats_get_stat_int32_ptr(steam_user_stats, pch_name, pdata);
}

void steam_api_manager::SteamAPI_ISteamInput_TriggerVibration(void* steam_input, uint64_t input_handle,
                                                              unsigned short usleftspeed, unsigned short usrightspeed)
{
    function_pointers::steam_api_input_trigger_vibration_ptr(steam_input, input_handle, usleftspeed, usrightspeed);
}

bool steam_api_manager::SteamAPI_ISteamUserStats_StoreStats(void* steam_user_stats)
{
    return function_pointers::steam_api_user_stats_store_stats_ptr(steam_user_stats);
}

uint64_t steam_api_manager::SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(
    void* steam_user_stats,
    const char* pch_leaderboard_name,
    void* eLeaderboardSortMethod,
    void* eLeaderboardDisplayType
)
{
    return function_pointers::steam_api_user_stats_find_or_create_leaderboard_ptr(
        steam_user_stats, pch_leaderboard_name, eLeaderboardSortMethod, eLeaderboardDisplayType);
}

int steam_api_manager::SteamAPI_ISteamFriends_GetFriendCount(void* instance_ptr, int friends_flag)
{
    return function_pointers::steam_api_i_steam_friends_count_ptr(instance_ptr, friends_flag);
}

uint64 steam_api_manager::SteamAPI_ISteamFriends_GetFriendByIndex(void* instance_ptr, int friend_index, int friends_flag)
{
    return function_pointers::steam_api_i_steam_get_friend_by_index_ptr(instance_ptr, friend_index, friends_flag);
}

const char* steam_api_manager::SteamAPI_ISteamFriends_GetFriendPersonaName(void* instance_ptr, uint64_t steamid_friend)
{
    return function_pointers::steam_api_i_steam_get_friend_persona_name_ptr(instance_ptr, steamid_friend);
}

const char* steam_api_manager::SteamAPI_ISteamFriends_GetFriendRichPresence(void* instance_ptr, uint64_t steamid_friend, const char* pch_key)
{
    return function_pointers::steam_api_i_steam_get_friend_rich_presence_ptr(instance_ptr, steamid_friend, pch_key);
}

bool steam_api_manager::SteamAPI_ISteamFriends_SetRichPresence(void* instance_ptr, const char* pch_key, const char* pch_value)
{
    return function_pointers::steam_api_i_steam_set_rich_presence_ptr(instance_ptr, pch_key, pch_value);
}

uint64_t steam_api_manager::SteamAPI_ISteamMatchmaking_CreateLobby(void* instance_ptr, ELobbyType elobby_type, int cmax_members)
{
    return function_pointers::steam_api_i_steam_create_lobby_ptr(instance_ptr, elobby_type, cmax_members);
}

EPersonaState steam_api_manager::SteamAPI_ISteamFriends_GetFriendPersonaState(void* instance_ptr, uint64_t steamid_friend)
{
    return function_pointers::steam_api_i_steam_get_friend_persona_state_ptr(instance_ptr, steamid_friend);
}

bool steam_api_manager::SteamAPI_ISteamMatchmaking_InviteUserToLobby(void* instance_ptr, uint64_t steamid_lobby, uint64_t steamid_invitee)
{
    return function_pointers::steam_api_i_steam_invite_user_to_lobby_ptr(instance_ptr, steamid_lobby, steamid_invitee);
}

void steam_api_manager::SteamAPI_ISteamMatchmaking_LeaveLobby(void* instance_ptr, uint64_t steamid_lobby)
{
    function_pointers::steam_api_i_steam_leave_lobby_ptr(instance_ptr, steamid_lobby);
}
