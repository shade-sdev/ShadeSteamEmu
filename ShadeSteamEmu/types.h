#pragma once

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

typedef void* (*SteamAPI_ISteamFriends_GetPersonaName_Ptr)(void* instance_ptr);
typedef void* (*SteamInternal_CreateInterface_GetPtr)(const char*);
typedef bool (*SteamAPI_ISteamApps_BIsSubscribedApp_GetPtr)(void* steam_apps_ptr, AppId_t app_id);
typedef bool (*SteamAPI_ISteamUser_BLoggedOn_GetPtr)(void* steam_user_ptr);
