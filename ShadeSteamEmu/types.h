#pragma once

#include <cstdint>

#include "steam/steam_api_common.h"
typedef bool (*SteamAPI_Init_GetPtr)();
typedef void* (*SteamAPI_GetHSteamPipe_GetPtr)();
typedef void* (*SteamAPI_GetHSteamUser_GetPtr)();

typedef void* (*SteamClient_GetPtr)();
typedef void* (*SteamAPI_ISteamClient_GetISteamUser_GetPtr)(void* steam_client_ptr,
                                                            void* hsteam_user_ptr,
                                                            void* hsteam_pipe_ptr,
                                                            const char* version);

typedef void* (*SteamAPI_ISteamClient_GetISteamFriends_Ptr)(void* steam_client_ptr,
                                                            void* hsteam_user_ptr,
                                                            void* hsteam_pipe_ptr,
                                                            const char* version);

typedef void* (*ISteamApps_GetPtr)(void* steam_client_ptr,
                                   void* hsteam_user_ptr,
                                   void* hsteam_pipe_ptr,
                                   const char* version);

typedef void* (*ISteamUtils_GetPtr)(void* steam_client_ptr,
                                    void* hsteam_pipe_ptr,
                                    const char* version);

typedef void* (*ISteamMatchMaking_GetPtr)(void* steam_client_ptr,
                                          void* hsteam_user_ptr,
                                          void* hsteam_pipe_ptr,
                                          const char* version);

typedef void* (*ISteamMatchMakingServers_GetPtr)(void* steam_client_ptr,
                                                 void* hsteam_user_ptr,
                                                 void* hsteam_pipe_ptr,
                                                 const char* version);

typedef void* (*ISteamUserStats_GetPtr)(void* steam_client_ptr,
                                        void* hsteam_user_ptr,
                                        void* hsteam_pipe_ptr,
                                        const char* version);

typedef void* (*ISteamNetworking_GetPtr)(void* steam_client_ptr,
                                         void* hsteam_user_ptr,
                                         void* hsteam_pipe_ptr,
                                         const char* version);

typedef void* (*ISteamRemoteStorage_GetPtr)(void* steam_client_ptr,
                                            void* hsteam_user_ptr,
                                            void* hsteam_pipe_ptr,
                                            const char* version);

typedef void* (*ISteamScreenShots_GetPtr)(void* steam_client_ptr,
                                          void* hsteam_user_ptr,
                                          void* hsteam_pipe_ptr,
                                          const char* version);

typedef void* (*ISteamGameSearch_GetPtr)(void* steam_client_ptr,
                                         void* hsteam_user_ptr,
                                         void* hsteam_pipe_ptr,
                                         const char* version);

typedef void* (*ISteamHTTP_GetPtr)(void* steam_client_ptr,
                                   void* hsteam_user_ptr,
                                   void* hsteam_pipe_ptr,
                                   const char* version);

typedef void* (*ISteamController_GetPtr)(void* steam_client_ptr,
                                         void* hsteam_user_ptr,
                                         void* hsteam_pipe_ptr,
                                         const char* version);

typedef void* (*ISteamUGC_GetPtr)(void* steam_client_ptr,
                                  void* hsteam_user_ptr,
                                  void* hsteam_pipe_ptr,
                                  const char* version);

typedef void* (*ISteamMusic_GetPtr)(void* steam_client_ptr,
                                    void* hsteam_user_ptr,
                                    void* hsteam_pipe_ptr,
                                    const char* version);

typedef void* (*ISteamMusicRemote_GetPtr)(void* steam_client_ptr,
                                          void* hsteam_user_ptr,
                                          void* hsteam_pipe_ptr,
                                          const char* version);

typedef void* (*ISteamHTMLSurface_GetPtr)(void* steam_client_ptr,
                                          void* hsteam_user_ptr,
                                          void* hsteam_pipe_ptr,
                                          const char* version);

typedef void* (*ISteamInventory_GetPtr)(void* steam_client_ptr,
                                        void* hsteam_user_ptr,
                                        void* hsteam_pipe_ptr,
                                        const char* version);

typedef void* (*ISteamVideo_GetPtr)(void* steam_client_ptr,
                                    void* hsteam_user_ptr,
                                    void* hsteam_pipe_ptr,
                                    const char* version);

typedef void* (*ISteamParentalSettings_GetPtr)(void* steam_client_ptr,
                                               void* hsteam_user_ptr,
                                               void* hsteam_pipe_ptr,
                                               const char* version);

typedef void* (*ISteamInput_GetPtr)(void* steam_client_ptr,
                                    void* hsteam_user_ptr,
                                    void* hsteam_pipe_ptr,
                                    const char* version);

typedef void* (*ISteamParties_GetPtr)(void* steam_client_ptr,
                                      void* hsteam_user_ptr,
                                      void* hsteam_pipe_ptr,
                                      const char* version);

typedef void* (*ISteamRemotePlay_GetPtr)(void* steam_client_ptr,
                                         void* hsteam_user_ptr,
                                         void* hsteam_pipe_ptr,
                                         const char* version);

typedef void* (*ISteamAppList_GetPtr)(void* steam_client_ptr,
                                      void* hsteam_user_ptr,
                                      void* hsteam_pipe_ptr,
                                      const char* version);

typedef void (*SteamAPI_Shutdown_Ptr)();
typedef uint32 (*SteamAPI_ISteamUser_GetAuthSessionTicket_Ptr)(void* steam_user, void* p_ticket, int cb_max_ticket, uint32* pcb_ticket, void* steam_network_identity);
typedef bool (*SteamAPI_SteamNetworkingIdentity_SetGenericString_Ptr)(void* steam_network_identity, const char* psz_string);
typedef bool (*SteamAPI_IsSteamRunning_Ptr)();
typedef bool (*SteamAPI_Input_Init_Ptr)(void* steam_input_ptr, bool b_explicitly_call_run_frame);
typedef void (*SteamAPI_EnableDeviceCallbacks_Ptr)(void* steam_input_ptr);
typedef void (*SteamAPI_ManualDispatch_Init_Ptr)();
typedef void* (*SteamInternal_FindOrCreateUserInterface_Ptr)(void* hsteam_user_ptr, const char* psz_version);
typedef void* (*SteamAPI_ISteamFriends_GetPersonaName_Ptr)(void* instance_ptr);
typedef void* (*SteamInternal_CreateInterface_GetPtr)(const char*);
typedef bool (*SteamAPI_ISteamApps_BIsSubscribedApp_GetPtr)(void* steam_apps_ptr, AppId_t app_id);
typedef bool (*SteamAPI_ISteamUser_BLoggedOn_GetPtr)(void* steam_user_ptr);
typedef bool (*SteamAPI_ISteamUserStats_SetStatInt32_Ptr)(void* steam_user_stats, const char* pch_name, int32_t ndata);
typedef uint64_t (*SteamAPI_ISteamUser_GetSteamID_Ptr)(void* steam_user);
typedef uint64_t (*SteamAPI_ISteamUserStats_RequestUserStats_Ptr)(void* steam_user_stats, uint64_t steamid_user);
typedef bool (*SteamAPI_ISteamApps_BIsDlcInstalled_Ptr)(void* steam_apps, uint32_t app_id);
typedef void (*SteamAPI_ManualDispatch_RunFrame_Ptr)(void* hsteampipe);
typedef bool (*SteamAPI_ManualDispatch_GetNextCallback_Ptr)(void* hsteampipe, void* p_callback_msg);
typedef void (*SteamAPI_ManualDispatch_FreeLastCallback_Ptr)(void* hsteampipe);
typedef bool (*SteamAPI_ISteamRemoteStorage_FileExists_Ptr)(void* steam_remote_storage, const char* pch_file);
typedef int (*SteamAPI_ISteamInput_GetConnectedControllers_Ptr)(void* steam_input, uint64_t* handles_out);
typedef void (*SteamAPI_ISteamInput_RunFrame_Ptr)(void* steam_input, bool b_reserved_value);
typedef bool (*SteamAPI_ISteamUserStats_GetStatFloat_Ptr)(void* steam_user_stats, const char* pch_name, float* pdata);
typedef bool (*SteamAPI_ISteamUserStats_GetStatInt32_Ptr)(void* steam_user_stats, const char* pch_name, int32_t* pdata);
typedef void (*SteamAPI_ISteamInput_TriggerVibration_Ptr)(void* steam_input, uint64_t input_handle, unsigned short usleftspeed, unsigned short usrightspeed);
typedef bool (*SteamAPI_ISteamUserStats_StoreStats_Ptr)(void* steam_user_stats);
typedef uint64_t (*SteamAPI_ISteamUserStats_FindOrCreateLeaderboard_Ptr)(void* steam_user_stats, const char* pch_leaderboard_name, void* eLeaderboardSortMethod, void* eLeaderboardDisplayType);
typedef int (*SteamAPI_ISteam_FriendsCount_Ptr)(void* instance_ptr, int friends_flag);
typedef uint64 (*SteamAPI_ISteam_GetFriendByIndex_Ptr)(void* instance_ptr, int friend_index, int friends_flag);
typedef const char* (*SteamAPI_ISteam_GetFriendPersonaName_Ptr)(void* instance_ptr, uint64_t steamid_friend);
typedef const char* (*SteamAPI_ISteam_GetFriendRichPresence_Ptr)(void* instance_ptr, uint64_t steamid_friend, const char* pch_key);
typedef bool (*SteamAPI_ISteam_SetRichPresence_Ptr)(void* instance_ptr, const char* pch_key, const char* pch_value);
typedef uint64_t (*SteamAPI_ISteam_CreateLobby_Ptr)(void* instance_ptr, ELobbyType elobby_type, int cmax_members);
typedef EPersonaState (*SteamAPI_ISteam_GetFriendPersonaState_Ptr)(void* instance_ptr, uint64_t steamid_friend);
typedef bool (*SteamAPI_ISteam_InviteUserToLobby_Ptr)(void* instance_ptr, uint64_t steamid_lobby, uint64_t steamid_invitee);
typedef void (*SteamAPI_ISteam_LeaveLobby_Ptr)(void* instance_ptr, uint64_t steamid_lobby);
typedef void (*SteamAPI_RegisterCallResult_Ptr)( void* call_back_back, uint64_t api_call);
typedef void (*SteamAPI_UnregisterCallResult_Ptr)( void* call_back_back, uint64_t api_call);
typedef void (*SteamAPI_UnregisterCallback_Ptr)(void* call_back_back);
typedef void (*SteamAPI_RunCallbacks_Ptr)();
typedef void (*SteamInternal_FindOrCreateGameServerInterface_Ptr)(void*, const char*);
typedef void (*SteamAPI_RegisterCallback_Ptr)(void* call_back_back, int i_callback);
typedef void (*SteamInternal_ContextInit_Ptr)(void*);
typedef bool (*SteamAPI_RestartAppIfNecessary_Ptr)(uint32);
typedef void (*SteamAPI_ISteamFriends_ClearRichPresence_Ptr)(void*);
