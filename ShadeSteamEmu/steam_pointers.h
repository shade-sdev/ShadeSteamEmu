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

    static SteamAPI_Shutdown_Ptr steam_api_shutdown_ptr;
    static SteamAPI_ISteamUser_GetAuthSessionTicket_Ptr steam_api_user_get_auth_session_ticket_ptr;
    static SteamAPI_SteamNetworkingIdentity_SetGenericString_Ptr steam_api_steam_networking_identity_set_generic_string_ptr;
    static SteamAPI_IsSteamRunning_Ptr steam_api_is_steam_running_ptr;
    static SteamAPI_Input_Init_Ptr steam_api_input_init_ptr;
    static SteamAPI_EnableDeviceCallbacks_Ptr steam_api_enable_device_callbacks_ptr;
    static SteamAPI_ManualDispatch_Init_Ptr steam_api_manualdispatch_init_ptr;
    static SteamInternal_FindOrCreateUserInterface_Ptr steam_internal_findorcreateuserinterface_ptr;
    static SteamAPI_ISteamFriends_GetPersonaName_Ptr get_persona_name_ptr;
    static SteamInternal_CreateInterface_GetPtr create_interface_ptr;
    static SteamAPI_ISteamApps_BIsSubscribedApp_GetPtr is_subscribed_app_ptr;
    static SteamAPI_ISteamUser_BLoggedOn_GetPtr blogged_ptr;
    static SteamAPI_ISteamUserStats_SetStatInt32_Ptr steam_api_user_stats_set_stat_int32_ptr;
    static SteamAPI_ISteamUser_GetSteamID_Ptr steam_api_user_get_steam_id_ptr;
    static SteamAPI_ISteamUserStats_RequestUserStats_Ptr steam_api_user_stats_request_user_stats_ptr;
    static SteamAPI_ISteamApps_BIsDlcInstalled_Ptr steam_api_apps_b_is_dlc_installed_ptr;
    static SteamAPI_ManualDispatch_RunFrame_Ptr steam_api_manual_dispatch_run_frame_ptr;
    static SteamAPI_ManualDispatch_GetNextCallback_Ptr steam_api_manual_dispatch_get_next_callback_ptr;
    static SteamAPI_ManualDispatch_FreeLastCallback_Ptr steam_api_manual_dispatch_free_last_callback_ptr;
    static SteamAPI_ISteamRemoteStorage_FileExists_Ptr steam_api_remote_storage_file_exists_ptr;
    static SteamAPI_ISteamInput_GetConnectedControllers_Ptr steam_api_input_get_connected_controllers_ptr;
    static SteamAPI_ISteamInput_RunFrame_Ptr steam_api_input_run_frame_ptr;
    static SteamAPI_ISteamUserStats_GetStatFloat_Ptr steam_api_user_stats_get_stat_float_ptr;
    static SteamAPI_ISteamUserStats_GetStatInt32_Ptr steam_api_user_stats_get_stat_int32_ptr;
    static SteamAPI_ISteamInput_TriggerVibration_Ptr steam_api_input_trigger_vibration_ptr;
    static SteamAPI_ISteamUserStats_StoreStats_Ptr steam_api_user_stats_store_stats_ptr;
    static SteamAPI_ISteamUserStats_FindOrCreateLeaderboard_Ptr steam_api_user_stats_find_or_create_leaderboard_ptr;

    static bool initialize_function_pointers();
    template <typename FuncPtrType>
    static FuncPtrType load_pointer(const char* lp_proc_name);
};
