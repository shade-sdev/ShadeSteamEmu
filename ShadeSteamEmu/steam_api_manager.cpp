#include "steam_api_manager.h"

#include <iostream>
#include "MinHook.h"
#include "steam_pointers.h"

const void* steam_api_manager::hooked_get_persona_name(void* instance_ptr)
{
    return jazz_man_name;
}

steam_api_manager::steam_api_manager()
{
    logfile_.open("steam_api_log.txt", std::ios_base::app);
    function_pointers::initialize_function_pointers();
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
