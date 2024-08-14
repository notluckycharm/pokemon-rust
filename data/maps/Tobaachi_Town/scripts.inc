.set LOCALID_STOP_GIRL, 6
.set LOCALID_MOM, 7

Tobaachi_Town_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TobaachiTown_OnTransition

	@ State descriptions for VAR_TOBAACHI_TOWN_STATE
	@ 1: Began Game
	@ 2: Set clock
	@ 3: Received Pokedex
	@ 4: Received Running Shoes
	.byte 0

TobaachiTown_OnTransition::
	setflag FLAG_VISITED_TOBAACHI_TOWN
	call_if_unset FLAG_RECEIVED_STARTER, TobaachiTown_EventScript_BlockSouthEntrance
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 4, TobaachiTown_EventScript_HideMom
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, TobaachiTown_EventScript_SetMominFrontofDoor
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, TobaachiTown_EventScript_HideMom
	end

TobaachiTown_EventScript_HideMom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	return

TobaachiTown_EventScript_BlockSouthEntrance::
	setobjectxyperm LOCALID_STOP_GIRL, 24, 39
	setobjectmovementtype LOCALID_STOP_GIRL, MOVEMENT_TYPE_FACE_LEFT
	return

TobaachiTown_EventScript_SetMominFrontofDoor::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
	call TobaachiTown_EventScript_SetMomLocation
	return 

TobaachiTown_EventScript_SetMomLocation::
	setobjectxyperm LOCALID_MOM, 23, 36
	return 

Tobaachi_Town_Script_ProfessorCBuckthorn_Lab::
	msgbox Tobaachi_Town_Text_ProfessorCBuckthorn_Lab, MSGBOX_DEFAULT
	releaseall
	end

Tobaachi_Town_EventScript_PlayersHouseSign::
	msgbox Tobaachi_Town_Test_Players_House, MSGBOX_DEFAULT
	releaseall
	end

Tobaachi_Town_EventScript_Zigzagoon::
	lock
	faceplayer
	msgbox Tobaachi_Town_Text_Zigzagoon, MSGBOX_NPC
	releaseall
	end

Tobaachi_Town_EventScript_NPC_1::
	lock
	faceplayer
	msgbox Tobaachi_Town_Text_NPC_1, MSGBOX_NPC
	release
	end

Tobaachi_Town_EventScript_Stop_Exit::
	goto_if_unset FLAG_RECEIVED_STARTER, Tobaachi_Town_EventScript_NPC2_Interact
	releaseall
	end

Tobaachi_Town_EventScript_NPC2_Interact::
	lockall
	applymovement LOCALID_STOP_GIRL, Common_Movement_FacePlayer
	msgbox Tobaachi_Town_Text_NPC2_Interact, MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Tobaachi_Town_Movement_PlayerStepBack
	waitmovement 0
	releaseall
	end

Tobaachi_Town_EventScript_NPC2_Interact2::
	lock
	faceplayer
	msgbox Tobaachi_Town_Text_ItsDangerousToGoOut, MSGBOX_NPC
	release
	end

Tobaachi_Town_Movement_PlayerStepBack::
	walk_up
	step_end

TobaachiTown_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, Tobaachi_Town_EventScript_Mom2
	msgbox TobaachiTown_Text_Mom, MSGBOX_AUTOCLOSE
	release
	call TobaachiTown_EventScript_GiveRunningShoes
	goto TobaachiTown_EventScript_SetReceivedRunningShoes
	end

Tobaachi_Town_EventScript_Mom2::
	msgbox Tobaachi_Town_Text_Mom2, MSGBOX_AUTOCLOSE
	release
	end

TobaachiTown_EventScript_GiveRunningShoes::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox Tobaachi_Town_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

TobaachiTown_EventScript_SetReceivedRunningShoes::
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	end

Tobaachi_Town_Text_ExplainRunningShoes:
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

Tobaachi_Town_Text_Mom2:
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

TobaachiTown_Text_Mom:
	.string "Oh, {PLAYER}!\n"
	.string "I see PROF. BUCKTHORN gave you a\l"
	.string "POKéDEX!\p"
	.string "I can't believe you're all grown up\n"
	.string "and starting an adventure of your own!\p"
	.string "I got you something that might\n"
	.string "be helpful. They're RUNNING SHOES!$"

Tobaachi_Town_Text_NPC2_Interact:
	.string "Wait!\p"
	.string "It's dangerous to go into the tall grass\n"
	.string "without a POKéMON\p"
	.string "You should go to PROF. BUCKTHORN's lab\n"
	.string "and get one before you go any further.$"

Tobaachi_Town_Text_NPC2_Interact2:
	.string "One day I want to be a POKéMON trainer,\n"
	.string "too.$"

Tobaachi_Town_Text_Zigzagoon:
	.string "GOON!$"

Tobaachi_Town_Text_ProfessorCBuckthorn_Lab:
	.string "Professor C. Buckthorn's Lab$"

Tobaachi_Town_Test_Players_House:
	.string "{PLAYER}'s HOUSE$"

Tobaachi_Town_Text_NPC_1:
	.string "The rivers here are said to be blessed by\n"
	.string "a mystical Water-type Pokémon that brings\l"
	.string "life to our lands.$"

Tobaachi_Town_Text_ItsDangerousToGoOut:
	.string "I hear that PROF. BUCKTHORN gives away\n"
	.string "POKéMON for free to potential new\p"
	.string "trainers!\p"
	.string "I wonder what kind of POKéMON\n"
	.string "I would get?$"
