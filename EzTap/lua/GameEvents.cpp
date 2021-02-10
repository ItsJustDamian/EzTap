#include "GameEvents.hpp"

GameEvents::GameEvents()
{
	interfaces.GameEventManager->addListener(this, "player_death");
	interfaces.GameEventManager->addListener(this, "other_death");
	interfaces.GameEventManager->addListener(this, "player_hurt");
	interfaces.GameEventManager->addListener(this, "item_purchase");
	interfaces.GameEventManager->addListener(this, "bomb_beginplant");
	interfaces.GameEventManager->addListener(this, "bomb_abortplant");
	interfaces.GameEventManager->addListener(this, "bomb_planted");
	interfaces.GameEventManager->addListener(this, "bomb_defused");
	interfaces.GameEventManager->addListener(this, "bomb_exploded");
	interfaces.GameEventManager->addListener(this, "bomb_dropped");
	interfaces.GameEventManager->addListener(this, "bomb_pickup");
	interfaces.GameEventManager->addListener(this, "defuser_dropped");
	interfaces.GameEventManager->addListener(this, "defuser_pickup");
	interfaces.GameEventManager->addListener(this, "announce_phase_end");
	interfaces.GameEventManager->addListener(this, "cs_intermission");
	interfaces.GameEventManager->addListener(this, "bomb_begindefuse");
	interfaces.GameEventManager->addListener(this, "bomb_abortdefuse");
	interfaces.GameEventManager->addListener(this, "hostage_follows");
	interfaces.GameEventManager->addListener(this, "hostage_hurt");
	interfaces.GameEventManager->addListener(this, "hostage_killed");
	interfaces.GameEventManager->addListener(this, "hostage_rescued");
	interfaces.GameEventManager->addListener(this, "hostage_stops_following");
	interfaces.GameEventManager->addListener(this, "hostage_rescued_all");
	interfaces.GameEventManager->addListener(this, "hostage_call_for_help");
	interfaces.GameEventManager->addListener(this, "vip_escaped");
	interfaces.GameEventManager->addListener(this, "vip_killed");
	interfaces.GameEventManager->addListener(this, "player_radio");
	interfaces.GameEventManager->addListener(this, "bomb_beep");
	interfaces.GameEventManager->addListener(this, "weapon_fire");
	interfaces.GameEventManager->addListener(this, "weapon_fire_on_empty");
	interfaces.GameEventManager->addListener(this, "grenade_thrown");
	interfaces.GameEventManager->addListener(this, "weapon_outofammo");
	interfaces.GameEventManager->addListener(this, "weapon_reload");
	interfaces.GameEventManager->addListener(this, "weapon_zoom");
	interfaces.GameEventManager->addListener(this, "silencer_detach");
	interfaces.GameEventManager->addListener(this, "inspect_weapon");
	interfaces.GameEventManager->addListener(this, "weapon_zoom_rifle");
	interfaces.GameEventManager->addListener(this, "player_spawned");
	interfaces.GameEventManager->addListener(this, "item_pickup");
	interfaces.GameEventManager->addListener(this, "item_pickup_slerp");
	interfaces.GameEventManager->addListener(this, "item_pickup_failed");
	interfaces.GameEventManager->addListener(this, "item_remove");
	interfaces.GameEventManager->addListener(this, "ammo_pickup");
	interfaces.GameEventManager->addListener(this, "item_equip");
	interfaces.GameEventManager->addListener(this, "enter_buyzone");
	interfaces.GameEventManager->addListener(this, "exit_buyzone");
	interfaces.GameEventManager->addListener(this, "buytime_ended");
	interfaces.GameEventManager->addListener(this, "enter_bombzone");
	interfaces.GameEventManager->addListener(this, "exit_bombzone");
	interfaces.GameEventManager->addListener(this, "enter_rescue_zone");
	interfaces.GameEventManager->addListener(this, "exit_rescue_zone");
	interfaces.GameEventManager->addListener(this, "silencer_off");
	interfaces.GameEventManager->addListener(this, "silencer_on");
	interfaces.GameEventManager->addListener(this, "buymenu_open");
	interfaces.GameEventManager->addListener(this, "buymenu_close");
	interfaces.GameEventManager->addListener(this, "round_prestart");
	interfaces.GameEventManager->addListener(this, "round_poststart");
	interfaces.GameEventManager->addListener(this, "round_start");
	interfaces.GameEventManager->addListener(this, "round_end");
	interfaces.GameEventManager->addListener(this, "grenade_bounce");
	interfaces.GameEventManager->addListener(this, "hegrenade_detonate");
	interfaces.GameEventManager->addListener(this, "flashbang_detonate");
	interfaces.GameEventManager->addListener(this, "smokegrenade_detonate");
	interfaces.GameEventManager->addListener(this, "smokegrenade_expired");
	interfaces.GameEventManager->addListener(this, "molotov_detonate");
	interfaces.GameEventManager->addListener(this, "decoy_detonate");
	interfaces.GameEventManager->addListener(this, "decoy_started");
	interfaces.GameEventManager->addListener(this, "tagrenade_detonate");
	interfaces.GameEventManager->addListener(this, "inferno_startburn");
	interfaces.GameEventManager->addListener(this, "inferno_expire");
	interfaces.GameEventManager->addListener(this, "inferno_extinguish");
	interfaces.GameEventManager->addListener(this, "decoy_firing");
	interfaces.GameEventManager->addListener(this, "bullet_impact");
	interfaces.GameEventManager->addListener(this, "player_footstep");
	interfaces.GameEventManager->addListener(this, "player_jump");
	interfaces.GameEventManager->addListener(this, "player_blind");
	interfaces.GameEventManager->addListener(this, "player_falldamage");
	interfaces.GameEventManager->addListener(this, "door_moving");
	interfaces.GameEventManager->addListener(this, "round_freeze_end");
	interfaces.GameEventManager->addListener(this, "mb_input_lock_success");
	interfaces.GameEventManager->addListener(this, "mb_input_lock_cancel");
	interfaces.GameEventManager->addListener(this, "nav_blocked");
	interfaces.GameEventManager->addListener(this, "nav_generate");
	interfaces.GameEventManager->addListener(this, "player_stats_updated");
	interfaces.GameEventManager->addListener(this, "achievement_info_loaded");
	interfaces.GameEventManager->addListener(this, "spec_target_updated");
	interfaces.GameEventManager->addListener(this, "spec_mode_updated");
	interfaces.GameEventManager->addListener(this, "hltv_changed_mode");
	interfaces.GameEventManager->addListener(this, "cs_game_disconnected");
	interfaces.GameEventManager->addListener(this, "cs_win_panel_round");
	interfaces.GameEventManager->addListener(this, "cs_win_panel_match");
	interfaces.GameEventManager->addListener(this, "cs_match_end_restart");
	interfaces.GameEventManager->addListener(this, "cs_pre_restart");
	interfaces.GameEventManager->addListener(this, "show_freezepanel");
	interfaces.GameEventManager->addListener(this, "hide_freezepanel");
	interfaces.GameEventManager->addListener(this, "freezecam_started");
	interfaces.GameEventManager->addListener(this, "player_avenged_teammate");
	interfaces.GameEventManager->addListener(this, "achievement_earned");
	interfaces.GameEventManager->addListener(this, "achievement_earned_local");
	interfaces.GameEventManager->addListener(this, "item_found");
	interfaces.GameEventManager->addListener(this, "items_gifted");
	interfaces.GameEventManager->addListener(this, "repost_xbox_achievements");
	interfaces.GameEventManager->addListener(this, "match_end_conditions");
	interfaces.GameEventManager->addListener(this, "round_mvp");
	interfaces.GameEventManager->addListener(this, "player_decal");
	interfaces.GameEventManager->addListener(this, "teamplay_round_start");
	interfaces.GameEventManager->addListener(this, "show_survival_respawn_status");
	interfaces.GameEventManager->addListener(this, "client_disconnect");
	interfaces.GameEventManager->addListener(this, "gg_player_levelup");
	interfaces.GameEventManager->addListener(this, "ggtr_player_levelup");
	interfaces.GameEventManager->addListener(this, "assassination_target_killed");
	interfaces.GameEventManager->addListener(this, "ggprogressive_player_levelup");
	interfaces.GameEventManager->addListener(this, "gg_killed_enemy");
	interfaces.GameEventManager->addListener(this, "gg_final_weapon_achieved");
	interfaces.GameEventManager->addListener(this, "gg_bonus_grenade_achieved");
	interfaces.GameEventManager->addListener(this, "switch_team");
	interfaces.GameEventManager->addListener(this, "gg_leader");
	interfaces.GameEventManager->addListener(this, "gg_team_leader");
	interfaces.GameEventManager->addListener(this, "gg_player_impending_upgrade");
	interfaces.GameEventManager->addListener(this, "write_profile_data");
	interfaces.GameEventManager->addListener(this, "trial_time_expired");
	interfaces.GameEventManager->addListener(this, "update_matchmaking_stats");
	interfaces.GameEventManager->addListener(this, "player_reset_vote");
	interfaces.GameEventManager->addListener(this, "enable_restart_voting");
	interfaces.GameEventManager->addListener(this, "sfuievent");
	interfaces.GameEventManager->addListener(this, "start_vote");
	interfaces.GameEventManager->addListener(this, "player_given_c4");
	interfaces.GameEventManager->addListener(this, "player_become_ghost");
	interfaces.GameEventManager->addListener(this, "gg_reset_round_start_sounds");
	interfaces.GameEventManager->addListener(this, "tr_player_flashbanged");
	interfaces.GameEventManager->addListener(this, "tr_mark_complete");
	interfaces.GameEventManager->addListener(this, "tr_mark_best_time");
	interfaces.GameEventManager->addListener(this, "tr_exit_hint_trigger");
	interfaces.GameEventManager->addListener(this, "bot_takeover");
	interfaces.GameEventManager->addListener(this, "tr_show_finish_msgbox");
	interfaces.GameEventManager->addListener(this, "tr_show_exit_msgbox");
	interfaces.GameEventManager->addListener(this, "reset_player_controls");
	interfaces.GameEventManager->addListener(this, "jointeam_failed");
	interfaces.GameEventManager->addListener(this, "teamchange_pending");
	interfaces.GameEventManager->addListener(this, "material_default_complete");
	interfaces.GameEventManager->addListener(this, "cs_prev_next_spectator");
	interfaces.GameEventManager->addListener(this, "cs_handle_ime_event");
	interfaces.GameEventManager->addListener(this, "nextlevel_changed");
	interfaces.GameEventManager->addListener(this, "seasoncoin_levelup");
	interfaces.GameEventManager->addListener(this, "tournament_reward");
	interfaces.GameEventManager->addListener(this, "start_halftime");
	interfaces.GameEventManager->addListener(this, "ammo_refill");
	interfaces.GameEventManager->addListener(this, "parachute_pickup");
	interfaces.GameEventManager->addListener(this, "parachute_deploy");
	interfaces.GameEventManager->addListener(this, "dronegun_attack");
	interfaces.GameEventManager->addListener(this, "drone_dispatched");
	interfaces.GameEventManager->addListener(this, "loot_crate_visible");
	interfaces.GameEventManager->addListener(this, "loot_crate_opened");
	interfaces.GameEventManager->addListener(this, "open_crate_instr");
	interfaces.GameEventManager->addListener(this, "smoke_beacon_paradrop");
	interfaces.GameEventManager->addListener(this, "survival_paradrop_spawn");
	interfaces.GameEventManager->addListener(this, "survival_paradrop_break");
	interfaces.GameEventManager->addListener(this, "drone_cargo_detached");
	interfaces.GameEventManager->addListener(this, "drone_above_roof");
	interfaces.GameEventManager->addListener(this, "choppers_incoming_warning");
	interfaces.GameEventManager->addListener(this, "firstbombs_incoming_warning");
	interfaces.GameEventManager->addListener(this, "dz_item_interaction");
	interfaces.GameEventManager->addListener(this, "snowball_hit_player_face");
	interfaces.GameEventManager->addListener(this, "survival_teammate_respawn");
	interfaces.GameEventManager->addListener(this, "survival_no_respawns_warning");
	interfaces.GameEventManager->addListener(this, "survival_no_respawns_final");
	interfaces.GameEventManager->addListener(this, "player_ping");
	interfaces.GameEventManager->addListener(this, "player_ping_stop");
	interfaces.GameEventManager->addListener(this, "guardian_wave_restart");
}

GameEvents::~GameEvents()
{
	interfaces.GameEventManager->removeListener(this);
}

void GameEvents::FireGameEvent(IGameEvent* pEvent)
{
	if (LocalPlayer && LocalPlayer->team() > 0)
	{
		ExportedGameEvent GameEvent(pEvent);
		LUAHooksExecWithArgs(GMEHooks, (GameEvent));
	}
}

int GameEvents::GetEventDebugID()
{
	return EVENT_DEBUG_ID_INIT;
}
