#pragma once

#pragma once
#include <fstream>
#include <ostream>

#include "steam/steam_api_common.h"

static auto jazz_man_name = "JazzMan";

class steam_api_manager
{
    std::ofstream logfile_;

    static const void* hooked_get_persona_name(void* instance_ptr);

public:
    steam_api_manager();

    ~steam_api_manager();

    steam_api_manager(const steam_api_manager& other) = delete;

    steam_api_manager& operator=(const steam_api_manager& other) = delete;

    steam_api_manager(steam_api_manager&& other) noexcept : logfile_(std::move(other.logfile_))
    {
    }

    steam_api_manager& operator=(steam_api_manager&& other) noexcept
    {
        if (this != &other)
        {
            logfile_ = std::move(other.logfile_);
        }
        return *this;
    }

    static bool install_hook();

    static bool SteamAPI_Init();

    static void* SteamAPI_GetHSteamUser();

    static void* SteamAPI_GetHSteamPipe();

    static void* SteamClient();

    static void* SteamAPI_ISteamClient_GetISteamUser(void* steam_client_ptr,
                                                     void* hsteam_user_ptr,
                                                     void* hsteam_pipe_ptr,
                                                     const char* version);
    
    static void* SteamAPI_ISteamClient_GetISteamApps(void* steam_client_ptr,
                                                     void* hsteam_user_ptr,
                                                     void* hsteam_pipe_ptr,
                                                     const char* version);

    static void* SteamAPI_ISteamClient_GetISteamFriends(void* steam_client_ptr,
                                                        void* hsteam_user_ptr,
                                                        void* hsteam_pipe_ptr,
                                                        const char* version);

    static void* SteamAPI_ISteamClient_GetISteamUtils(void* steam_client_ptr,
                                                      void* hsteam_pipe_ptr,
                                                      const char* version);

    static void* SteamAPI_ISteamClient_GetISteamMatchmaking(void* steam_client_ptr,
                                                            void* hsteam_user_ptr,
                                                            void* hsteam_pipe_ptr,
                                                            const char* version);

    static void* SteamAPI_ISteamClient_GetISteamMatchmakingServers(void* steam_client_ptr,
                                                                   void* hsteam_user_ptr,
                                                                   void* hsteam_pipe_ptr,
                                                                   const char* version);

    static void* SteamAPI_ISteamClient_GetISteamUserStats(void* steam_client_ptr,
                                                          void* hsteam_user_ptr,
                                                          void* hsteam_pipe_ptr,
                                                          const char* version);

    static void* SteamAPI_ISteamClient_GetISteamNetworking(void* steam_client_ptr,
                                                           void* hsteam_user_ptr,
                                                           void* hsteam_pipe_ptr,
                                                           const char* version);

    static void* SteamAPI_ISteamClient_GetISteamRemoteStorage(void* steam_client_ptr,
                                                              void* hsteam_user_ptr,
                                                              void* hsteam_pipe_ptr,
                                                              const char* version);

    static void* SteamAPI_ISteamClient_GetISteamScreenshots(void* steam_client_ptr,
                                                            void* hsteam_user_ptr,
                                                            void* hsteam_pipe_ptr,
                                                            const char* version);

    static void* SteamAPI_ISteamClient_GetISteamGameSearch(void* steam_client_ptr,
                                                           void* hsteam_user_ptr,
                                                           void* hsteam_pipe_ptr,
                                                           const char* version);

    static void* SteamAPI_ISteamClient_GetISteamHTTP(void* steam_client_ptr,
                                                     void* hsteam_user_ptr,
                                                     void* hsteam_pipe_ptr,
                                                     const char* version);

    static void* SteamAPI_ISteamClient_GetISteamController(void* steam_client_ptr,
                                                           void* hsteam_user_ptr,
                                                           void* hsteam_pipe_ptr,
                                                           const char* version);

    static void* SteamAPI_ISteamClient_GetISteamUGC(void* steam_client_ptr,
                                                    void* hsteam_user_ptr,
                                                    void* hsteam_pipe_ptr,
                                                    const char* version);

    static void* SteamAPI_ISteamClient_GetISteamMusic(void* steam_client_ptr,
                                                      void* hsteam_user_ptr,
                                                      void* hsteam_pipe_ptr,
                                                      const char* version);

    static void* SteamAPI_ISteamClient_GetISteamMusicRemote(void* steam_client_ptr,
                                                            void* hsteam_user_ptr,
                                                            void* hsteam_pipe_ptr,
                                                            const char* version);

    static void* SteamAPI_ISteamClient_GetISteamHTMLSurface(void* steam_client_ptr,
                                                            void* hsteam_user_ptr,
                                                            void* hsteam_pipe_ptr,
                                                            const char* version);

    static void* SteamAPI_ISteamClient_GetISteamInventory(void* steam_client_ptr,
                                                          void* hsteam_user_ptr,
                                                          void* hsteam_pipe_ptr,
                                                          const char* version);

    static void* SteamAPI_ISteamClient_GetISteamVideo(void* steam_client_ptr,
                                                      void* hsteam_user_ptr,
                                                      void* hsteam_pipe_ptr,
                                                      const char* version);

    static void* SteamAPI_ISteamClient_GetISteamParentalSettings(void* steam_client_ptr,
                                                                 void* hsteam_user_ptr,
                                                                 void* hsteam_pipe_ptr,
                                                                 const char* version);

    static void* SteamAPI_ISteamClient_GetISteamInput(void* steam_client_ptr,
                                                      void* hsteam_user_ptr,
                                                      void* hsteam_pipe_ptr,
                                                      const char* version);

    static void* SteamAPI_ISteamClient_GetISteamParties(void* steam_client_ptr,
                                                        void* hsteam_user_ptr,
                                                        void* hsteam_pipe_ptr,
                                                        const char* version);

    static void* SteamAPI_ISteamClient_GetISteamRemotePlay(void* steam_client_ptr,
                                                           void* hsteam_user_ptr,
                                                           void* hsteam_pipe_ptr,
                                                           const char* version);

    static void* SteamAPI_ISteamClient_GetISteamAppList(void* steam_client_ptr,
                                                           void* hsteam_user_ptr,
                                                           void* hsteam_pipe_ptr,
                                                           const char* version);
    
    static void* SteamAPI_ISteamFriends_GetPersonaName(void* steam_friends_ptr);

    static bool SteamAPI_ISteamApps_BIsSubscribedApp(void* steam_apps_ptr, uint32 app_id);

    static bool SteamAPI_ISteamUser_BLoggedOn(void* steam_user_ptr);

    static void* SteamInternal_CreateInterface(const char* version);

    static void* SteamInternal_FindOrCreateUserInterface(void* hsteam_user_ptr, const char* psz_version);

    static void SteamAPI_ManualDispatch_Init();

    static void SteamAPI_ISteamInput_EnableDeviceCallbacks(void* steam_input_ptr);

    static bool SteamAPI_ISteamInput_Init(void* steam_input_ptr, bool b_explicitly_call_run_frame);

    static bool SteamAPI_IsSteamRunning();
    
    static bool SteamAPI_SteamNetworkingIdentity_SetGenericString(void* steam_network_identity, const char* psz_string);
    
    static uint32 SteamAPI_ISteamUser_GetAuthSessionTicket(void* steam_user, void* p_ticket, int cb_max_ticket, uint32* pcb_ticket, void* steam_network_identity);

    static void SteamAPI_Shutdown();
    
    static bool SteamAPI_ISteamUserStats_SetStatInt32(void* steam_user_stats, const char* pch_name, int32_t ndata);

    static uint64_t SteamAPI_ISteamUser_GetSteamID(void* steam_user);
    
    static uint64_t SteamAPI_ISteamUserStats_RequestUserStats(void* steam_user_stats, uint64_t steamid_user);

    static bool SteamAPI_ISteamApps_BIsDlcInstalled(void* steam_apps, uint32_t app_id);
    
    static void SteamAPI_ManualDispatch_RunFrame(void* hsteampipe);

    static bool SteamAPI_ManualDispatch_GetNextCallback(void* hsteampipe, void* p_callback_msg);

    static void SteamAPI_ManualDispatch_FreeLastCallback(void* hsteampipe);

    static bool SteamAPI_ISteamRemoteStorage_FileExists(void* steam_remote_storage, const char* pch_file);

    static int SteamAPI_ISteamInput_GetConnectedControllers(void* steam_input, uint64_t* handles_out);

    static void SteamAPI_ISteamInput_RunFrame(void* steam_input, bool b_reserved_value);
    
    static bool SteamAPI_ISteamUserStats_GetStatFloat(void* steam_user_stats, const char* pch_name, float* pdata);

    static bool SteamAPI_ISteamUserStats_GetStatInt32(void* steam_user_stats, const char* pch_name, int32_t* pdata);

    static void SteamAPI_ISteamInput_TriggerVibration(void* steam_input, uint64_t input_handle, unsigned short usleftspeed, unsigned short usrightspeed);

    static bool SteamAPI_ISteamUserStats_StoreStats(void* steam_user_stats);

    static uint64_t SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(void* steam_user_stats, const char* pch_leaderboard_name, void* eLeaderboardSortMethod, void* eLeaderboardDisplayType);

};
