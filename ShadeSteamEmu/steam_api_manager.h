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

    static void* SteamInternal_CreateInterface(const char* version);

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

    static void* SteamAPI_ISteamFriends_GetPersonaName(void* steam_friends_ptr);

    static bool SteamAPI_ISteamApps_BIsSubscribedApp(void* steam_apps_ptr, uint32 app_id);

    static bool SteamAPI_ISteamUser_BLoggedOn(void* steam_user_ptr);
};
