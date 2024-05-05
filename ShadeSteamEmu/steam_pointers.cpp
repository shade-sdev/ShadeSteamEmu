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
ISteamMatchMakingServers_GetPtr function_pointers::steam_match_making_servers_ptr = nullptr;
ISteamUserStats_GetPtr function_pointers::steam_user_stats_ptr = nullptr;
ISteamNetworking_GetPtr function_pointers::steam_networking_ptr = nullptr;
ISteamRemoteStorage_GetPtr function_pointers::steam_remote_storage_ptr = nullptr;
ISteamScreenShots_GetPtr function_pointers::steam_screen_shots_ptr = nullptr;
ISteamGameSearch_GetPtr function_pointers::steam_game_search_ptr = nullptr;
ISteamHTTP_GetPtr function_pointers::steam_http_ptr = nullptr;
ISteamController_GetPtr function_pointers::steam_controller_ptr = nullptr;
ISteamUGC_GetPtr function_pointers::steam_ugc_ptr = nullptr;
ISteamMusic_GetPtr function_pointers::steam_music_ptr = nullptr;
ISteamMusicRemote_GetPtr function_pointers::steam_music_remote_ptr = nullptr;
ISteamHTMLSurface_GetPtr function_pointers::steam_htmlsurface_ptr = nullptr;
ISteamInventory_GetPtr function_pointers::steam_inventory_ptr = nullptr;
ISteamVideo_GetPtr function_pointers::steam_video_ptr = nullptr;
ISteamParentalSettings_GetPtr function_pointers::steam_parentalsettings_ptr = nullptr;
ISteamInput_GetPtr function_pointers::steam_input_ptr = nullptr;
ISteamParties_GetPtr function_pointers::steam_parties_ptr = nullptr;
ISteamRemotePlay_GetPtr function_pointers::steam_remoteplay_ptr = nullptr;
ISteamAppList_GetPtr function_pointers::steam_app_list_ptr = nullptr;

SteamAPI_IsSteamRunning_Ptr function_pointers::steam_api_is_steam_running_ptr = nullptr;
SteamAPI_Input_Init_Ptr function_pointers::steam_api_input_init_ptr = nullptr;
SteamAPI_EnableDeviceCallbacks_Ptr function_pointers::steam_api_enable_device_callbacks_ptr = nullptr;
SteamAPI_ManualDispatch_Init_Ptr function_pointers::steam_api_manualdispatch_init_ptr = nullptr;
SteamAPI_ISteamFriends_GetPersonaName_Ptr function_pointers::get_persona_name_ptr = nullptr;
SteamInternal_CreateInterface_GetPtr function_pointers::create_interface_ptr = nullptr;
SteamAPI_ISteamApps_BIsSubscribedApp_GetPtr function_pointers::is_subscribed_app_ptr = nullptr;
SteamAPI_ISteamUser_BLoggedOn_GetPtr function_pointers::blogged_ptr = nullptr;
SteamInternal_FindOrCreateUserInterface_Ptr function_pointers::steam_internal_findorcreateuserinterface_ptr = nullptr;
SteamAPI_SteamNetworkingIdentity_SetGenericString_Ptr
function_pointers::steam_api_steam_networking_identity_set_generic_string_ptr = nullptr;
SteamAPI_ISteamUser_GetAuthSessionTicket_Ptr function_pointers::steam_api_user_get_auth_session_ticket_ptr = nullptr;
SteamAPI_Shutdown_Ptr function_pointers::steam_api_shutdown_ptr = nullptr;
SteamAPI_ISteamUserStats_SetStatInt32_Ptr function_pointers::steam_api_user_stats_set_stat_int32_ptr = nullptr;
SteamAPI_ISteamUser_GetSteamID_Ptr function_pointers::steam_api_user_get_steam_id_ptr = nullptr;
SteamAPI_ISteamUserStats_RequestUserStats_Ptr function_pointers::steam_api_user_stats_request_user_stats_ptr = nullptr;
SteamAPI_ISteamApps_BIsDlcInstalled_Ptr function_pointers::steam_api_apps_b_is_dlc_installed_ptr = nullptr;
SteamAPI_ManualDispatch_RunFrame_Ptr function_pointers::steam_api_manual_dispatch_run_frame_ptr = nullptr;
SteamAPI_ManualDispatch_GetNextCallback_Ptr function_pointers::steam_api_manual_dispatch_get_next_callback_ptr =
    nullptr;
SteamAPI_ManualDispatch_FreeLastCallback_Ptr function_pointers::steam_api_manual_dispatch_free_last_callback_ptr =
    nullptr;
SteamAPI_ISteamRemoteStorage_FileExists_Ptr function_pointers::steam_api_remote_storage_file_exists_ptr = nullptr;
SteamAPI_ISteamInput_GetConnectedControllers_Ptr function_pointers::steam_api_input_get_connected_controllers_ptr =
    nullptr;
SteamAPI_ISteamInput_RunFrame_Ptr function_pointers::steam_api_input_run_frame_ptr = nullptr;
SteamAPI_ISteamUserStats_GetStatFloat_Ptr function_pointers::steam_api_user_stats_get_stat_float_ptr = nullptr;
SteamAPI_ISteamUserStats_GetStatInt32_Ptr function_pointers::steam_api_user_stats_get_stat_int32_ptr = nullptr;
SteamAPI_ISteamInput_TriggerVibration_Ptr function_pointers::steam_api_input_trigger_vibration_ptr = nullptr;
SteamAPI_ISteamUserStats_StoreStats_Ptr function_pointers::steam_api_user_stats_store_stats_ptr = nullptr;
SteamAPI_ISteamUserStats_FindOrCreateLeaderboard_Ptr
function_pointers::steam_api_user_stats_find_or_create_leaderboard_ptr = nullptr;
SteamAPI_ISteam_FriendsCount_Ptr function_pointers::steam_api_i_steam_friends_count_ptr = nullptr;
SteamAPI_ISteam_GetFriendByIndex_Ptr function_pointers::steam_api_i_steam_get_friend_by_index_ptr = nullptr;
SteamAPI_ISteam_GetFriendPersonaName_Ptr function_pointers::steam_api_i_steam_get_friend_persona_name_ptr = nullptr;
SteamAPI_ISteam_GetFriendRichPresence_Ptr function_pointers::steam_api_i_steam_get_friend_rich_presence_ptr = nullptr;
SteamAPI_ISteam_SetRichPresence_Ptr function_pointers::steam_api_i_steam_set_rich_presence_ptr = nullptr;
SteamAPI_ISteam_CreateLobby_Ptr function_pointers::steam_api_i_steam_create_lobby_ptr = nullptr;
SteamAPI_ISteam_GetFriendPersonaState_Ptr function_pointers::steam_api_i_steam_get_friend_persona_state_ptr = nullptr;
SteamAPI_ISteam_InviteUserToLobby_Ptr function_pointers::steam_api_i_steam_invite_user_to_lobby_ptr = nullptr;
SteamAPI_ISteam_LeaveLobby_Ptr function_pointers::steam_api_i_steam_leave_lobby_ptr = nullptr;
SteamAPI_RegisterCallResult_Ptr function_pointers::steam_api_register_call_result_ptr = nullptr;
SteamAPI_UnregisterCallResult_Ptr function_pointers::steam_api_unregister_call_result_ptr = nullptr;
SteamAPI_UnregisterCallback_Ptr function_pointers::steam_api_unregister_callback_ptr = nullptr;
SteamAPI_RunCallbacks_Ptr function_pointers::steam_api_run_callbacks_ptr = nullptr;
SteamInternal_FindOrCreateGameServerInterface_Ptr function_pointers::find_or_create_game_server_interface_ptr = nullptr;
SteamAPI_RegisterCallback_Ptr function_pointers::register_callback_ptr = nullptr;
SteamInternal_ContextInit_Ptr function_pointers::context_init_ptr = nullptr;
SteamAPI_RestartAppIfNecessary_Ptr function_pointers::restart_app_if_necessary_ptr = nullptr;
SteamAPI_ISteamFriends_ClearRichPresence_Ptr function_pointers::clear_rich_presence_ptr = nullptr;

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
    steam_match_making_servers_ptr = load_pointer<ISteamMatchMakingServers_GetPtr>(
        steam_api_steamclient_isteammatchmakingservers);
    steam_user_stats_ptr = load_pointer<ISteamUserStats_GetPtr>(steam_api_steamclient_isteamuserstats);
    steam_networking_ptr = load_pointer<ISteamNetworking_GetPtr>(steam_api_steamclient_isteamnetworking);
    steam_remote_storage_ptr = load_pointer<ISteamRemoteStorage_GetPtr>(steam_api_steamclient_isteamremotestorage);
    steam_screen_shots_ptr = load_pointer<ISteamScreenShots_GetPtr>(steam_api_steamclient_isteamscreenshots);
    steam_game_search_ptr = load_pointer<ISteamGameSearch_GetPtr>(steam_api_steamclient_isteamgamesearch);
    steam_http_ptr = load_pointer<ISteamHTTP_GetPtr>(steam_api_steamclient_isteamhttp);
    steam_controller_ptr = load_pointer<ISteamController_GetPtr>(steam_api_steamclient_isteamcontroller);
    steam_ugc_ptr = load_pointer<ISteamUGC_GetPtr>(steam_api_steamclient_isteamugc);
    steam_music_ptr = load_pointer<ISteamMusic_GetPtr>(steam_api_steamclient_isteammusic);
    steam_music_remote_ptr = load_pointer<ISteamMusicRemote_GetPtr>(steam_api_steamclient_isteammusicremote);
    steam_htmlsurface_ptr = load_pointer<ISteamHTMLSurface_GetPtr>(steam_api_steamclient_isteamhtmlsurface);
    steam_inventory_ptr = load_pointer<ISteamInventory_GetPtr>(steam_api_steamclient_isteaminventory);
    steam_video_ptr = load_pointer<ISteamVideo_GetPtr>(steam_api_steamclient_isteamvideo);
    steam_parentalsettings_ptr = load_pointer<ISteamParentalSettings_GetPtr>(
        steam_api_steamclient_isteamparentalsettings);
    steam_input_ptr = load_pointer<ISteamInput_GetPtr>(steam_api_steamclient_isteaminput);
    steam_parties_ptr = load_pointer<ISteamParties_GetPtr>(steam_api_steamclient_isteamparties);
    steam_remoteplay_ptr = load_pointer<ISteamRemotePlay_GetPtr>(steam_api_steamclient_isteamremoteplay);
    steam_app_list_ptr = load_pointer<ISteamAppList_GetPtr>(steam_api_steamclient_isteamapplist);

    steam_api_is_steam_running_ptr = load_pointer<SteamAPI_IsSteamRunning_Ptr>(steam_is_steam_running);
    steam_api_input_init_ptr = load_pointer<SteamAPI_Input_Init_Ptr>(steam_api_steam_input_init);
    steam_api_enable_device_callbacks_ptr = load_pointer<SteamAPI_EnableDeviceCallbacks_Ptr>(
        steam_api_enable_device_callbacks);
    steam_api_manualdispatch_init_ptr = load_pointer<SteamAPI_ManualDispatch_Init_Ptr>(steam_api_manualdispatch_init);
    get_persona_name_ptr = load_pointer<
        SteamAPI_ISteamFriends_GetPersonaName_Ptr>(steam_api_isteamfriends_persona_name);
    create_interface_ptr = load_pointer<SteamInternal_CreateInterface_GetPtr>(steaminternal_create_interface);
    steam_internal_findorcreateuserinterface_ptr = load_pointer<SteamInternal_FindOrCreateUserInterface_Ptr>(
        steam_internal_findorcreateuserinterface);
    is_subscribed_app_ptr = load_pointer<SteamAPI_ISteamApps_BIsSubscribedApp_GetPtr>(
        steam_api_steamapps_bissubscribedapp);
    blogged_ptr = load_pointer<SteamAPI_ISteamUser_BLoggedOn_GetPtr>(steam_api_steamuser_bloggedon);
    steam_api_steam_networking_identity_set_generic_string_ptr =
        load_pointer<SteamAPI_SteamNetworkingIdentity_SetGenericString_Ptr>(
            steam_networking_identity_set_generic_string);
    steam_api_user_get_auth_session_ticket_ptr = load_pointer<SteamAPI_ISteamUser_GetAuthSessionTicket_Ptr>(
        steam_user_get_auth_session_ticket);
    steam_api_shutdown_ptr = load_pointer<SteamAPI_Shutdown_Ptr>(steam_shutdown);
    steam_api_user_stats_set_stat_int32_ptr = load_pointer<SteamAPI_ISteamUserStats_SetStatInt32_Ptr>(
        steam_user_stats_set_stat_int32);
    steam_api_user_get_steam_id_ptr = load_pointer<SteamAPI_ISteamUser_GetSteamID_Ptr>(steam_user_get_steam_id);
    steam_api_user_stats_request_user_stats_ptr = load_pointer<SteamAPI_ISteamUserStats_RequestUserStats_Ptr>(
        steam_user_stats_request_user_stats);
    steam_api_apps_b_is_dlc_installed_ptr = load_pointer<SteamAPI_ISteamApps_BIsDlcInstalled_Ptr>(
        steam_apps_b_is_dlc_installed);
    steam_api_manual_dispatch_run_frame_ptr = load_pointer<SteamAPI_ManualDispatch_RunFrame_Ptr>(
        steam_manual_dispatch_run_frame);
    steam_api_manual_dispatch_get_next_callback_ptr = load_pointer<SteamAPI_ManualDispatch_GetNextCallback_Ptr>(
        steam_manual_dispatch_get_next_callback);
    steam_api_manual_dispatch_free_last_callback_ptr = load_pointer<SteamAPI_ManualDispatch_FreeLastCallback_Ptr>(
        steam_manual_dispatch_free_last_callback);
    steam_api_remote_storage_file_exists_ptr = load_pointer<SteamAPI_ISteamRemoteStorage_FileExists_Ptr>(
        steam_remote_storage_file_exists);
    steam_api_input_get_connected_controllers_ptr = load_pointer<SteamAPI_ISteamInput_GetConnectedControllers_Ptr>(
        steam_input_get_connected_controllers);
    steam_api_input_run_frame_ptr = load_pointer<SteamAPI_ISteamInput_RunFrame_Ptr>(steam_input_run_frame);
    steam_api_user_stats_get_stat_float_ptr = load_pointer<SteamAPI_ISteamUserStats_GetStatFloat_Ptr>(
        steam_user_stats_get_stat_float);
    steam_api_user_stats_get_stat_int32_ptr = load_pointer<SteamAPI_ISteamUserStats_GetStatInt32_Ptr>(
        steam_user_stats_get_stat_int32);
    steam_api_input_trigger_vibration_ptr = load_pointer<SteamAPI_ISteamInput_TriggerVibration_Ptr>(
        steam_input_trigger_vibration);
    steam_api_user_stats_store_stats_ptr = load_pointer<SteamAPI_ISteamUserStats_StoreStats_Ptr>(
        steam_user_stats_store_stats);
    steam_api_user_stats_find_or_create_leaderboard_ptr = load_pointer<
        SteamAPI_ISteamUserStats_FindOrCreateLeaderboard_Ptr>(steam_user_stats_find_or_create_leaderboard);
    steam_api_i_steam_friends_count_ptr = load_pointer<SteamAPI_ISteam_FriendsCount_Ptr>(steam_friends_count);
    steam_api_i_steam_get_friend_by_index_ptr = load_pointer<SteamAPI_ISteam_GetFriendByIndex_Ptr>(
        steam_friends_get_friend_by_index);
    steam_api_i_steam_get_friend_persona_name_ptr = load_pointer<SteamAPI_ISteam_GetFriendPersonaName_Ptr>(
        steam_friends_get_friend_persona_name);
    steam_api_i_steam_get_friend_rich_presence_ptr = load_pointer<SteamAPI_ISteam_GetFriendRichPresence_Ptr>(
        steam_friends_get_friend_rich_presence);
    steam_api_i_steam_set_rich_presence_ptr = load_pointer<SteamAPI_ISteam_SetRichPresence_Ptr>(
        steam_friends_set_rich_presence);
    steam_api_i_steam_create_lobby_ptr = load_pointer<SteamAPI_ISteam_CreateLobby_Ptr>(steam_matchmaking_create_lobby);
    steam_api_i_steam_get_friend_persona_state_ptr = load_pointer<SteamAPI_ISteam_GetFriendPersonaState_Ptr>(
        steam_friends_get_friend_persona_state);
    steam_api_i_steam_invite_user_to_lobby_ptr = load_pointer<SteamAPI_ISteam_InviteUserToLobby_Ptr>(
        steam_matchmaking_invite_user_to_lobby);
    steam_api_i_steam_leave_lobby_ptr = load_pointer<SteamAPI_ISteam_LeaveLobby_Ptr>(
        steam_matchmaking_leave_lobby);
    steam_api_register_call_result_ptr = load_pointer<SteamAPI_RegisterCallResult_Ptr>(
        steam_register_call_result);
    steam_api_unregister_call_result_ptr = load_pointer<SteamAPI_UnregisterCallResult_Ptr >(
        steam_unregister_call_result );
    steam_api_unregister_callback_ptr = load_pointer<SteamAPI_UnregisterCallback_Ptr >(
    steam_unregister_callback  );
    steam_api_run_callbacks_ptr = load_pointer<SteamAPI_RunCallbacks_Ptr >(
    steam_run_callbacks   );
    find_or_create_game_server_interface_ptr = load_pointer<SteamInternal_FindOrCreateGameServerInterface_Ptr>(steaminternal_find_or_create_game_server_interface);
    register_callback_ptr = load_pointer<SteamAPI_RegisterCallback_Ptr>(steamapi_register_callback);
    context_init_ptr = load_pointer<SteamInternal_ContextInit_Ptr>(steaminternal_context_init);
    restart_app_if_necessary_ptr = load_pointer<SteamAPI_RestartAppIfNecessary_Ptr>(steamapi_restart_app_if_necessary);
    clear_rich_presence_ptr = load_pointer<SteamAPI_ISteamFriends_ClearRichPresence_Ptr>(steamapi_isteamfriends_clear_rich_presence);

    return hsteam_pipe_ptr && hsteam_user_ptr && steam_client_ptr &&
        steam_user_ptr && steam_friends_ptr && get_persona_name_ptr &&
        create_interface_ptr && steam_apps_ptr && is_subscribed_app_ptr && blogged_ptr
        && steam_api_manualdispatch_init_ptr && context_init_ptr && register_callback_ptr;
}

template <typename FuncPtrType>
FuncPtrType function_pointers::load_pointer(const char* lp_proc_name)
{
    return reinterpret_cast<FuncPtrType>(GetProcAddress(steam_api_64_dll, lp_proc_name));
}
