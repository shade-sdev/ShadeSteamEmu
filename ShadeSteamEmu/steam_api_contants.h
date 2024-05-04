#pragma once

constexpr auto steam_api_init = "SteamAPI_Init";
constexpr auto steam_api_hsteampipe = "SteamAPI_GetHSteamPipe";
constexpr auto steam_api_hsteamuser = "SteamAPI_GetHSteamUser";

constexpr auto steam_client = "SteamClient";
constexpr auto steam_api_steamclient_isteamuser = "SteamAPI_ISteamClient_GetISteamUser";
constexpr auto steam_api_steamclient_isteamfriends = "SteamAPI_ISteamClient_GetISteamFriends";
constexpr auto steam_api_steamclient_isteamapps = "SteamAPI_ISteamClient_GetISteamApps";
constexpr auto steam_api_steamclient_isteamutils = "SteamAPI_ISteamClient_GetISteamUtils";
constexpr auto steam_api_steamclient_isteammatchmaking = "SteamAPI_ISteamClient_GetISteamMatchmaking";
constexpr auto steam_api_steamclient_isteammatchmakingservers = "SteamAPI_ISteamClient_GetISteamMatchmakingServers";
constexpr auto steam_api_steamclient_isteamuserstats = "SteamAPI_ISteamClient_GetISteamUserStats";
constexpr auto steam_api_steamclient_isteamnetworking = "SteamAPI_ISteamClient_GetISteamNetworking";
constexpr auto steam_api_steamclient_isteamremotestorage = "SteamAPI_ISteamClient_GetISteamRemoteStorage";
constexpr auto steam_api_steamclient_isteamscreenshots = "SteamAPI_ISteamClient_GetISteamScreenshots";
constexpr auto steam_api_steamclient_isteamgamesearch = "SteamAPI_ISteamClient_GetISteamGameSearch";
constexpr auto steam_api_steamclient_isteamhttp = "SteamAPI_ISteamClient_GetISteamHTTP";
constexpr auto steam_api_steamclient_isteamcontroller = "SteamAPI_ISteamClient_GetISteamController";
constexpr auto steam_api_steamclient_isteamugc = "SteamAPI_ISteamClient_GetISteamUGC";
constexpr auto steam_api_steamclient_isteammusic = "SteamAPI_ISteamClient_GetISteamMusic";
constexpr auto steam_api_steamclient_isteammusicremote = "SteamAPI_ISteamClient_GetISteamMusicRemote";
constexpr auto steam_api_steamclient_isteamhtmlsurface = "SteamAPI_ISteamClient_GetISteamHTMLSurface";
constexpr auto steam_api_steamclient_isteaminventory = "SteamAPI_ISteamClient_GetISteamInventory";
constexpr auto steam_api_steamclient_isteamvideo = "SteamAPI_ISteamClient_GetISteamVideo";
constexpr auto steam_api_steamclient_isteamparentalsettings = "SteamAPI_ISteamClient_GetISteamParentalSettings";
constexpr auto steam_api_steamclient_isteaminput = "SteamAPI_ISteamClient_GetISteamInput";
constexpr auto steam_api_steamclient_isteamparties = "SteamAPI_ISteamClient_GetISteamParties";
constexpr auto steam_api_steamclient_isteamremoteplay = "SteamAPI_ISteamClient_GetISteamRemotePlay";
constexpr auto steam_api_steamclient_isteamapplist = "SteamAPI_ISteamClient_GetISteamAppList";

constexpr auto steam_user_stats_set_stat_int32 = "SteamAPI_ISteamUserStats_SetStatInt32";
constexpr auto steam_shutdown = "SteamAPI_Shutdown";
constexpr auto steam_user_get_auth_session_ticket = "SteamAPI_ISteamUser_GetAuthSessionTicket";
constexpr auto steam_networking_identity_set_generic_string = "SteamAPI_SteamNetworkingIdentity_SetGenericString";
constexpr auto steam_is_steam_running = "SteamAPI_IsSteamRunning";
constexpr auto steam_api_steam_input_init = "SteamAPI_ISteamInput_Init";
constexpr auto steam_api_enable_device_callbacks = "SteamAPI_ISteamInput_EnableDeviceCallbacks";
constexpr auto steam_api_manualdispatch_init = "SteamAPI_ManualDispatch_Init";
constexpr auto steam_internal_findorcreateuserinterface = "SteamInternal_FindOrCreateUserInterface";
constexpr auto steam_api_isteamfriends_persona_name = "SteamAPI_ISteamFriends_GetPersonaName";
constexpr auto steaminternal_create_interface = "SteamInternal_CreateInterface";
constexpr auto steam_api_steamapps_bissubscribedapp = "SteamAPI_ISteamApps_BIsSubscribedApp";
constexpr auto steam_api_steamuser_bloggedon = "SteamAPI_ISteamUser_BLoggedOn";
constexpr auto steam_user_get_steam_id = "SteamAPI_ISteamUser_GetSteamID";
constexpr auto steam_user_stats_request_user_stats = "SteamAPI_ISteamUserStats_RequestUserStats";
constexpr auto steam_apps_b_is_dlc_installed = "SteamAPI_ISteamApps_BIsDlcInstalled";
constexpr auto steam_manual_dispatch_run_frame = "SteamAPI_ManualDispatch_RunFrame";
constexpr auto steam_manual_dispatch_get_next_callback = "SteamAPI_ManualDispatch_GetNextCallback";
constexpr auto steam_manual_dispatch_free_last_callback = "SteamAPI_ManualDispatch_FreeLastCallback";
constexpr auto steam_remote_storage_file_exists = "SteamAPI_ISteamRemoteStorage_FileExists";
constexpr auto steam_input_get_connected_controllers = "SteamAPI_ISteamInput_GetConnectedControllers";
constexpr auto steam_input_run_frame = "SteamAPI_ISteamInput_RunFrame";
constexpr auto steam_user_stats_get_stat_float = "SteamAPI_ISteamUserStats_GetStatFloat";
constexpr auto steam_user_stats_get_stat_int32 = "SteamAPI_ISteamUserStats_GetStatInt32";
constexpr auto steam_input_trigger_vibration = "SteamAPI_ISteamInput_TriggerVibration";
constexpr auto steam_user_stats_store_stats = "SteamAPI_ISteamUserStats_StoreStats";
constexpr auto steam_user_stats_find_or_create_leaderboard = "SteamAPI_ISteamUserStats_FindOrCreateLeaderboard";
constexpr auto steam_friends_count= "SteamAPI_ISteamFriends_GetFriendCount";
constexpr auto steam_friends_get_friend_by_index = "SteamAPI_ISteamFriends_GetFriendByIndex";
constexpr auto steam_friends_get_friend_persona_name = "SteamAPI_ISteamFriends_GetFriendPersonaName";
constexpr auto steam_friends_get_friend_rich_presence = "SteamAPI_ISteamFriends_GetFriendRichPresence";
constexpr auto steam_friends_set_rich_presence = "SteamAPI_ISteamFriends_SetRichPresence";
constexpr auto steam_matchmaking_create_lobby = "SteamAPI_ISteamMatchmaking_CreateLobby";
constexpr auto steam_friends_get_friend_persona_state = "SteamAPI_ISteamFriends_GetFriendPersonaState";
constexpr auto steam_matchmaking_invite_user_to_lobby = "SteamAPI_ISteamMatchmaking_InviteUserToLobby";
constexpr auto steam_matchmaking_leave_lobby = "SteamAPI_ISteamMatchmaking_LeaveLobby";
constexpr auto steam_register_call_result = "SteamAPI_RegisterCallResult";
constexpr auto steam_unregister_call_result = "SteamAPI_UnregisterCallResult";
constexpr auto steam_unregister_callback = "SteamAPI_UnregisterCallback";
constexpr auto steam_run_callbacks = "SteamAPI_RunCallbacks";
constexpr auto steaminternal_find_or_create_game_server_interface = "SteamInternal_FindOrCreateGameServerInterface";
constexpr auto steamapi_register_callback = "SteamAPI_RegisterCallback";
constexpr auto steaminternal_context_init = "SteamInternal_ContextInit";
