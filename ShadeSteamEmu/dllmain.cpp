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
