#include <windows.h>
#include "steam_api_manager.h"

steam_api_manager* steam_api_manager = nullptr;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        steam_api_manager = new class steam_api_manager;
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

extern "C" __declspec(dllexport) void* SteamInternal_CreateInterface(const char* version)
{
    return steam_api_manager::SteamInternal_CreateInterface(version);
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
