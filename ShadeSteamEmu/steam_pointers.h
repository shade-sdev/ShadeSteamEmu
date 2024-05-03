#pragma once

#include <windows.h>

#include "types.h"

class function_pointers
{
public:
    static HMODULE steam_api_64_dll;

    static SteamAPI_Init_GetPtr steam_init_ptr;
    static SteamAPI_GetHSteamPipe_GetPtr hsteam_pipe_ptr;
    static SteamAPI_GetHSteamUser_GetPtr hsteam_user_ptr;

    static SteamClient_GetPtr steam_client_ptr;
    static SteamAPI_ISteamClient_GetISteamUser_GetPtr steam_user_ptr;
    static SteamAPI_ISteamClient_GetISteamFriends_Ptr steam_friends_ptr;
    static ISteamApps_GetPtr steam_apps_ptr;
    static ISteamUtils_GetPtr steam_utils_ptr;
    static ISteamMatchMaking_GetPtr steam_matchmaking_ptr;
    static ISteamMatchMakingServers_GetPtr steam_match_making_servers_ptr;
    static ISteamUserStats_GetPtr steam_user_stats_ptr;
    static ISteamNetworking_GetPtr steam_networking_ptr;
    static ISteamRemoteStorage_GetPtr steam_remote_storage_ptr;
    static ISteamScreenShots_GetPtr steam_screen_shots_ptr;
    static ISteamGameSearch_GetPtr steam_game_search_ptr;
    static ISteamHTTP_GetPtr steam_http_ptr;
    static ISteamController_GetPtr steam_controller_ptr;
    static ISteamUGC_GetPtr steam_ugc_ptr;
    static ISteamMusic_GetPtr steam_music_ptr;
    static ISteamMusicRemote_GetPtr steam_music_remote_ptr;
    static ISteamHTMLSurface_GetPtr steam_htmlsurface_ptr;
    static ISteamInventory_GetPtr steam_inventory_ptr;
    static ISteamVideo_GetPtr steam_video_ptr;
    static ISteamParentalSettings_GetPtr steam_parentalsettings_ptr;
    static ISteamInput_GetPtr steam_input_ptr;
    static ISteamParties_GetPtr steam_parties_ptr;
    static ISteamRemotePlay_GetPtr steam_remoteplay_ptr;
    static ISteamAppList_GetPtr steam_app_list_ptr;
    
    static SteamAPI_ISteamFriends_GetPersonaName_Ptr get_persona_name_ptr;
    static SteamInternal_CreateInterface_GetPtr create_interface_ptr;
    static SteamAPI_ISteamApps_BIsSubscribedApp_GetPtr is_subscribed_app_ptr;
    static SteamAPI_ISteamUser_BLoggedOn_GetPtr blogged_ptr;

    static bool initialize_function_pointers();
    template <typename FuncPtrType>
    static FuncPtrType load_pointer(const char* lp_proc_name);
};
