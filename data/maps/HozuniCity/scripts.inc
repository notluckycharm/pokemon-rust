HozuniCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HozuniCity_OnTransition
	@ State descriptions for VAR_HOZUNI_CITY_STATE
	@ 0: Unvisited
	@ 1: Talked to Gym Guy
	@ 2: Talked to Trainer School Prof
	@ 3: Met Blaze in Ruins
	.byte 0

HozuniCity_OnTransition::
	setflag FLAG_VISITED_HOZUNI_CITY
	call_if_eq VAR_HOZUNI_CITY_STATE, 3, HozuniCity_HideGymGuy
	end

HozuniCity_HideGymGuy::
	setflag FLAG_HIDE_HOZUNICITY_GYMGUY
	return

HozuniCity_EventScript_TownSign::
	msgbox HozuniCity_Text_TownSign, MSGBOX_SIGN
	end

HozuniCity_EventScript_BlazeNotHere::
	msgbox HozuniCity_Text_BlazeNotHere, MSGBOX_NPC
	call_if_eq VAR_HOZUNI_CITY_STATE, 0, HozuniCity_Incr_State
	release
	end

HozuniCity_Incr_State::
	setvar VAR_HOZUNI_CITY_STATE, 1
	end

HozuniCity_EventScript_TrainerSchoolSign::
	msgbox HozuniCity_Text_TrainerSchoolSign, MSGBOX_SIGN
	end

HozuniCity_Text_TrainerSchoolSign:
	.string "POKéMON TRAINER SCHOOL$"

HozuniCity_Text_BlazeNotHere:
	.string "Looking to challenge the HOZUNI CITY\n"
	.string "GYM Leader, BLAZE?\p"
	.string "Well you're just out of luck.\n"
	.string "He disappeared off somewhere.\p"
	.string "Last I saw him, he went into the\n"
	.string "TRAINER SCHOOL.\p"
	.string "Maybe you could try there?$"

HozuniCity_Text_TownSign:
	.string "HOZUNI CITY\n"
	.string "The City Where Sand Meets Sea.$"
	