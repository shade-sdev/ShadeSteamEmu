#include <windows.h>
#include "steam_api_manager.h"

steam_api_manager* steam_api_manager = nullptr;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        steam_api_manager = new class steam_api_manager;
        steam_api_manager::SteamAPI_Init();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    default:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) bool SteamAPI_Init()
{
    return steam_api_manager::SteamAPI_Init();
}

extern "C" __declspec(dllexport) void* SteamAPI_GetHSteamUser()
{
    return steam_api_manager::SteamAPI_GetHSteamUser();
}

extern "C" __declspec(dllexport) void* SteamAPI_GetHSteamPipe()
{
    return steam_api_manager::SteamAPI_GetHSteamPipe();
}

extern "C" __declspec(dllexport) void* SteamClient()
{
    return steam_api_manager::SteamClient();
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamUser(void* steam_client_ptr,
                                                                           void* hsteam_user_ptr,
                                                                           void* hsteam_pipe_ptr,
                                                                           const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamUser(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr,
                                                                  version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamApps(void* steam_client_ptr,
                                                                           void* hsteam_user_ptr,
                                                                           void* hsteam_pipe_ptr,
                                                                           const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamApps(steam_client_ptr, hsteam_user_ptr, hsteam_pipe_ptr,
                                                                  version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamFriends(void* steam_client_ptr,
                                                                              void* hsteam_user_ptr,
                                                                              void* hsteam_pipe_ptr,
                                                                              const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamFriends(steam_client_ptr,
                                                                     hsteam_user_ptr,
                                                                     hsteam_pipe_ptr,
                                                                     version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamUtils(void* steam_client_ptr,
                                                                            void* hsteam_pipe_ptr,
                                                                            const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamUtils(steam_client_ptr, hsteam_pipe_ptr, version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamMatchmaking(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamMatchmaking(steam_client_ptr,
                                                                         hsteam_user_ptr,
                                                                         hsteam_pipe_ptr,
                                                                         version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamMatchmakingServers(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamMatchmakingServers(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamUserStats(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamUserStats(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamNetworking(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamNetworking(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamRemoteStorage(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamRemoteStorage(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamScreenshots(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamScreenshots(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamGameSearch(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamGameSearch(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamHTTP(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamHTTP(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamController(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamController(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamUGC(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamUGC(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamMusic(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamMusic(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamMusicRemote(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamMusicRemote(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamHTMLSurface(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamHTMLSurface(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamInventory(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamInventory(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamVideo(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamVideo(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamParentalSettings(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamParentalSettings(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamInput(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamInput(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamParties(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamParties(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamRemotePlay(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamRemotePlay(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamClient_GetISteamAppList(
    void* steam_client_ptr,
    void* hsteam_user_ptr,
    void* hsteam_pipe_ptr,
    const char* version)
{
    return steam_api_manager::SteamAPI_ISteamClient_GetISteamAppList(
        steam_client_ptr,
        hsteam_user_ptr,
        hsteam_pipe_ptr,
        version
    );
}

extern "C" __declspec(dllexport) void SteamAPI_ManualDispatch_Init()
{
    return steam_api_manager::SteamAPI_ManualDispatch_Init();
}

extern "C" __declspec(dllexport) void SteamAPI_ISteamInput_EnableDeviceCallbacks(void* steam_input_ptr)
{
    return steam_api_manager::SteamAPI_ISteamInput_EnableDeviceCallbacks(steam_input_ptr);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamInput_Init(void* steam_input_ptr,
                                                                const bool b_explicitly_call_run_frame)
{
    return steam_api_manager::SteamAPI_ISteamInput_Init(steam_input_ptr, b_explicitly_call_run_frame);
}

extern "C" __declspec(dllexport) bool SteamAPI_IsSteamRunning()
{
    return steam_api_manager::SteamAPI_IsSteamRunning();
}

extern "C" __declspec(dllexport) void* SteamInternal_FindOrCreateUserInterface(void* hsteam_user_ptr,
                                                                               const char* psz_version)
{
    return steam_api_manager::SteamInternal_FindOrCreateUserInterface(
        hsteam_user_ptr,
        psz_version
    );
}

extern "C" __declspec(dllexport) void* SteamInternal_CreateInterface(const char* version)
{
    return steam_api_manager::SteamInternal_CreateInterface(version);
}

extern "C" __declspec(dllexport) void* SteamAPI_ISteamFriends_GetPersonaName(void* steam_friends_ptr)
{
    return steam_api_manager::SteamAPI_ISteamFriends_GetPersonaName(steam_friends_ptr);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamApps_BIsSubscribedApp(void* steam_apps_ptr, const uint32 appId)
{
    return steam_api_manager::SteamAPI_ISteamApps_BIsSubscribedApp(steam_apps_ptr, appId);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamUser_BLoggedOn(void* steam_user_ptr)
{
    return steam_api_manager::SteamAPI_ISteamUser_BLoggedOn(steam_user_ptr);
}

extern "C" __declspec(dllexport) bool SteamAPI_SteamNetworkingIdentity_SetGenericString(
    void* steam_network_identity, const char* psz_string)
{
    return steam_api_manager::SteamAPI_SteamNetworkingIdentity_SetGenericString(steam_network_identity, psz_string);
}

extern "C" __declspec(dllexport) uint32 SteamAPI_ISteamUser_GetAuthSessionTicket(void* steam_user,
    void* p_ticket,
    int cb_max_ticket,
    uint32* pcb_ticket,
    void* steam_network_identity)
{
    return steam_api_manager::SteamAPI_ISteamUser_GetAuthSessionTicket(steam_user,
                                                                       p_ticket,
                                                                       cb_max_ticket,
                                                                       pcb_ticket,
                                                                       steam_network_identity);
}

extern "C" __declspec(dllexport) void SteamAPI_Shutdown()
{
    steam_api_manager::SteamAPI_Shutdown();
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamUserStats_SetStatInt32(void* steam_user_stats, const char* pch_name, int32_t ndata)
{
    return steam_api_manager::SteamAPI_ISteamUserStats_SetStatInt32(steam_user_stats, pch_name, ndata);
}

extern "C" __declspec(dllexport) uint64_t SteamAPI_ISteamUser_GetSteamID(void* steam_user)
{
    return steam_api_manager::SteamAPI_ISteamUser_GetSteamID(steam_user);
}

extern "C" __declspec(dllexport) uint64_t SteamAPI_ISteamUserStats_RequestUserStats(void* steam_user_stats, uint64_t steamid_user)
{
    return steam_api_manager::SteamAPI_ISteamUserStats_RequestUserStats(steam_user_stats, steamid_user);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamApps_BIsDlcInstalled(void* steam_apps, uint32_t app_id)
{
    return steam_api_manager::SteamAPI_ISteamApps_BIsDlcInstalled(steam_apps, app_id);
}

extern "C" __declspec(dllexport) void SteamAPI_ManualDispatch_RunFrame(void* hsteampipe)
{
    steam_api_manager::SteamAPI_ManualDispatch_RunFrame(hsteampipe);
}

extern "C" __declspec(dllexport) bool SteamAPI_ManualDispatch_GetNextCallback(void* hsteampipe, void* p_callback_msg)
{
    return steam_api_manager::SteamAPI_ManualDispatch_GetNextCallback(hsteampipe, p_callback_msg);
}

extern "C" __declspec(dllexport) void SteamAPI_ManualDispatch_FreeLastCallback(void* hsteampipe)
{
    steam_api_manager::SteamAPI_ManualDispatch_FreeLastCallback(hsteampipe);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamRemoteStorage_FileExists(void* steam_remote_storage, const char* pch_file)
{
    return steam_api_manager::SteamAPI_ISteamRemoteStorage_FileExists(steam_remote_storage, pch_file);
}

extern "C" __declspec(dllexport) int SteamAPI_ISteamInput_GetConnectedControllers(void* steam_input, uint64_t* handles_out)
{
    return steam_api_manager::SteamAPI_ISteamInput_GetConnectedControllers(steam_input, handles_out);
}

extern "C" __declspec(dllexport) void SteamAPI_ISteamInput_RunFrame(void* steam_input, bool b_reserved_value)
{
    steam_api_manager::SteamAPI_ISteamInput_RunFrame(steam_input, b_reserved_value);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamUserStats_GetStatFloat(void* steam_user_stats, const char* pch_name, float* pdata)
{
    return steam_api_manager::SteamAPI_ISteamUserStats_GetStatFloat(steam_user_stats, pch_name, pdata);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamUserStats_GetStatInt32(void* steam_user_stats, const char* pch_name, int32_t* pdata)
{
    return steam_api_manager::SteamAPI_ISteamUserStats_GetStatInt32(steam_user_stats, pch_name, pdata);
}

extern "C" __declspec(dllexport) void SteamAPI_ISteamInput_TriggerVibration(void* steam_input, uint64_t input_handle, unsigned short usleftspeed, unsigned short usrightspeed)
{
    steam_api_manager::SteamAPI_ISteamInput_TriggerVibration(steam_input, input_handle, usleftspeed, usrightspeed);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamUserStats_StoreStats(void* steam_user_stats)
{
    return steam_api_manager::SteamAPI_ISteamUserStats_StoreStats(steam_user_stats);
}

extern "C" __declspec(dllexport) uint64_t SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(void* steam_user_stats, const char* pch_leaderboard_name, void* eLeaderboardSortMethod, void* eLeaderboardDisplayType)
{
    return steam_api_manager::SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(steam_user_stats, pch_leaderboard_name, eLeaderboardSortMethod, eLeaderboardDisplayType);
}

extern "C" __declspec(dllexport) int SteamAPI_ISteamFriends_GetFriendCount(void* instance_ptr, const int friends_flag)
{
    return steam_api_manager::SteamAPI_ISteamFriends_GetFriendCount(instance_ptr, friends_flag);
}

extern "C" __declspec(dllexport) uint64 SteamAPI_ISteamFriends_GetFriendByIndex(void* instance_ptr, int friend_index, const int friends_flag)
{
    return steam_api_manager::SteamAPI_ISteamFriends_GetFriendByIndex(instance_ptr, friend_index, friends_flag);
}

extern "C" __declspec(dllexport) const char* SteamAPI_ISteamFriends_GetFriendPersonaName(void* instance_ptr, uint64_t steamid_friend)
{
    return steam_api_manager::SteamAPI_ISteamFriends_GetFriendPersonaName(instance_ptr, steamid_friend);
}

extern "C" __declspec(dllexport) const char* SteamAPI_ISteamFriends_GetFriendRichPresence(void* instance_ptr, uint64_t steamid_friend, const char* pch_key)
{
    return steam_api_manager::SteamAPI_ISteamFriends_GetFriendRichPresence(instance_ptr, steamid_friend, pch_key);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamFriends_SetRichPresence(void* instance_ptr, const char* pch_key, const char* pch_value)
{
    return steam_api_manager::SteamAPI_ISteamFriends_SetRichPresence(instance_ptr, pch_key, pch_value);
}

extern "C" __declspec(dllexport) uint64_t SteamAPI_ISteamMatchmaking_CreateLobby(void* instance_ptr, ELobbyType elobby_type, int cmax_members)
{
    return steam_api_manager::SteamAPI_ISteamMatchmaking_CreateLobby(instance_ptr, elobby_type, cmax_members);
}

extern "C" __declspec(dllexport) EPersonaState SteamAPI_ISteamFriends_GetFriendPersonaState(void* instance_ptr, uint64_t steamid_friend)
{
    return steam_api_manager::SteamAPI_ISteamFriends_GetFriendPersonaState(instance_ptr, steamid_friend);
}

extern "C" __declspec(dllexport) bool SteamAPI_ISteamMatchmaking_InviteUserToLobby(void* instance_ptr, uint64_t steamid_lobby, uint64_t steamid_invitee)
{
    return steam_api_manager::SteamAPI_ISteamMatchmaking_InviteUserToLobby(instance_ptr, steamid_lobby, steamid_invitee);
}

extern "C" __declspec(dllexport) void SteamAPI_ISteamMatchmaking_LeaveLobby(void* instance_ptr, uint64_t steamid_lobby)
{
    steam_api_manager::SteamAPI_ISteamMatchmaking_LeaveLobby(instance_ptr, steamid_lobby);
}

extern "C" __declspec(dllexport) void SteamAPI_RegisterCallResult(CCallbackBase* pCallback, uint64_t api_call)
{
    steam_api_manager::SteamAPI_RegisterCallResult(pCallback, api_call);
}

extern "C" __declspec(dllexport) void SteamAPI_UnregisterCallResult(CCallbackBase* pCallback, uint64_t api_call)
{
    steam_api_manager::SteamAPI_UnregisterCallResult(pCallback, api_call);
}

extern "C" __declspec(dllexport) void SteamAPI_UnregisterCallback(CCallbackBase* pCallback)
{
    steam_api_manager::SteamAPI_UnregisterCallback(pCallback);
}

extern "C" __declspec(dllexport) void SteamAPI_RunCallbacks()
{
    steam_api_manager::SteamAPI_RunCallbacks();
}

extern "C" __declspec(dllexport) void SteamInternal_FindOrCreateGameServerInterface(void* h_steam_user, const char* version)
{
    return steam_api_manager::SteamInternal_FindOrCreateGameServerInterface(h_steam_user, version);
}

extern "C" __declspec(dllexport) void SteamAPI_RegisterCallback(CCallbackBase* p_callback, int i_callback)
{
    return steam_api_manager::SteamAPI_RegisterCallback(p_callback, i_callback);
}

extern "C" __declspec(dllexport) void SteamInternal_ContextInit(void* p_context_init_data)
{
    return steam_api_manager::SteamInternal_ContextInit(p_context_init_data);
}