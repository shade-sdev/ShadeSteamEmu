#include "steam_pointers.h"

#include "steam_api_contants.h"
#include "types.h"

HMODULE function_pointers::steam_api_64_dll = nullptr;
SteamAPI_Init_GetPtr function_pointers::steam_init_ptr = nullptr;
SteamAPI_GetHSteamPipe_GetPtr function_pointers::hsteam_pipe_ptr = nullptr;
SteamAPI_GetHSteamUser_GetPtr function_pointers::hsteam_user_ptr = nullptr;

SteamClient_GetPtr function_pointers::steam_client_ptr = nullptr;
SteamAPI_ISteamClient_GetISteamUser_GetPtr function_pointers::steam_user_ptr = nullptr;
SteamAPI_ISteamClient_GetISteamFriends_Ptr function_pointers::steam_friends_ptr = nullptr;
ISteamApps_GetPtr function_pointers::steam_apps_ptr = nullptr;
ISteamUtils_GetPtr function_pointers::steam_utils_ptr = nullptr;
ISteamMatchMaking_GetPtr function_pointers::steam_matchmaking_ptr = nullptr;

SteamAPI_ISteamFriends_GetPersonaName_Ptr function_pointers::get_persona_name_ptr = nullptr;
SteamInternal_CreateInterface_GetPtr function_pointers::create_interface_ptr = nullptr;
SteamAPI_ISteamApps_BIsSubscribedApp_GetPtr function_pointers::is_subscribed_app_ptr = nullptr;
SteamAPI_ISteamUser_BLoggedOn_GetPtr function_pointers::blogged_ptr = nullptr;

bool function_pointers::initialize_function_pointers()
{
    steam_api_64_dll = LoadLibraryA("steam_api64_o.dll");
    if (steam_api_64_dll == nullptr)
    {
        return false;
    }

    steam_init_ptr = load_pointer<SteamAPI_Init_GetPtr>(steam_api_init);
    hsteam_pipe_ptr = load_pointer<SteamAPI_GetHSteamPipe_GetPtr>(steam_api_hsteampipe);
    hsteam_user_ptr = load_pointer<SteamAPI_GetHSteamUser_GetPtr>(steam_api_hsteamuser);

    steam_client_ptr = load_pointer<SteamClient_GetPtr>(steam_client);
    steam_user_ptr = load_pointer<SteamAPI_ISteamClient_GetISteamUser_GetPtr>(steam_api_steamclient_isteamuser);
    steam_friends_ptr = load_pointer<SteamAPI_ISteamClient_GetISteamFriends_Ptr>(
        steam_api_steamclient_isteamfriends);
    steam_apps_ptr = load_pointer<ISteamApps_GetPtr>(steam_api_steamclient_isteamapps);
    steam_utils_ptr = load_pointer<ISteamUtils_GetPtr>(steam_api_steamclient_isteamutils);
    steam_matchmaking_ptr = load_pointer<ISteamMatchMaking_GetPtr>(steam_api_steamclient_isteammatchmaking);
    
    get_persona_name_ptr = load_pointer<SteamAPI_ISteamFriends_GetPersonaName_Ptr>(steam_api_isteamfriends_persona_name);
    create_interface_ptr = load_pointer<SteamInternal_CreateInterface_GetPtr>(steaminternal_create_interface);
    is_subscribed_app_ptr = load_pointer<SteamAPI_ISteamApps_BIsSubscribedApp_GetPtr>(steam_api_steamapps_bissubscribedapp);
    blogged_ptr = load_pointer<SteamAPI_ISteamUser_BLoggedOn_GetPtr>(steam_api_steamuser_bloggedon);

    return hsteam_pipe_ptr && hsteam_user_ptr && steam_client_ptr &&
        steam_user_ptr && steam_friends_ptr && get_persona_name_ptr &&
        create_interface_ptr && steam_apps_ptr && is_subscribed_app_ptr && blogged_ptr;
}

template <typename FuncPtrType>
FuncPtrType function_pointers::load_pointer(const char* lp_proc_name)
{
    return reinterpret_cast<FuncPtrType>(GetProcAddress(steam_api_64_dll, lp_proc_name));
}
