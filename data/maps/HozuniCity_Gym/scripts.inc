HozuniCity_Gym_MapScripts::
	.byte 0

HozuniCity_Gym_EventScript_Trainer1::
	trainerbattle_single TRAINER_BUCKY, HozuniCity_Gym_Text_BuckyIntro, HozuniCity_Gym_Text_BuckyDefeated
	msgbox HozuniCity_Gym_Text_BuckyDefeated, MSGBOX_AUTOCLOSE
	release
	end

HozuniCity_Gym_EventScript_Trainer2::
	trainerbattle_single TRAINER_FELICITY, HozuniCity_Gym_Text_FelicityIntro, HozuniCity_Gym_Text_FelicityDefeat
	msgbox HozuniCity_Gym_Text_FelicityDefeated, MSGBOX_AUTOCLOSE
	release
	end

HozuniCity_Gym_EventScript_Blaze::
	trainerbattle_single TRAINER_ROXANNE_1, HozuniCity_Gym_Text_BlazeIntro, HozuniCity_Gym_Text_BlazeDefeat, HozuniCity_Gym_EventScript_BlazeDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, HozuniCity_Gym_EventScript_GiveFireSpin
	msgbox HozuniCity_Gym_Text_BlazePostBattle, MSGBOX_DEFAULT
	release
	end

HozuniCity_Gym_EventScript_BlazeDefeated::
	message HozuniCity_Gym_Text_ReceivedEmberBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox HozuniCity_Gym_Text_EmberBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto HozuniCity_Gym_EventScript_GiveFireSpin
	end

HozuniCity_Gym_EventScript_GiveFireSpin::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox HozuniCity_Gym_Text_ExplainFireSpin, MSGBOX_DEFAULT
	release
	end

HozuniCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, HozuniCity_Gym_EventScript_GymStatueCertified
	goto HozuniCity_Gym_EventScript_GymStatue
	end

HozuniCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, HozuniCity_Gym_EventScript_GymStatueCertified
	goto HozuniCity_Gym_EventScript_GymStatue
	end

HozuniCity_Gym_EventScript_GymStatueCertified::
	msgbox HozuniCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

HozuniCity_Gym_EventScript_GymStatue::
	msgbox HozuniCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall

HozuniCity_Gym_Text_BuckyIntro:
	.string "Stop right there!\p"
	.string "Before you get to Blaze, I need to\n"
	.string "make sure you're ready. Bring it on!$"

HozuniCity_Gym_Text_BuckyDefeat:
	.string "Okay, you're pretty strong.$"

HozuniCity_Gym_Text_BuckyDefeated:
	.string "As a GYM TRAINER, my duty is to\n"
	.string "make sure all challengers are worthy\p"
	.string "Looks like you've passed my test.$"

HozuniCity_Gym_Text_BlazeIntro:
	.string "Hiya! I'm Blaze, the HOZUNI\n"
	.string "POKéMON GYM LEADER.\p"
	.string "I became a GYM LEADER because I love\n"
	.string "to fight super heated battles with my\l"
	.string "FIRE TYPE POKéMON.\p"
	.string "Do you think you can handle the heat?$"

HozuniCity_Gym_Text_BlazeDefeat:
	.string "Wow!\n"
	.string "What a flaming hot finish.\p"
	.string "It seems that I still need to practice\n"
	.string "much more.\p"
	.string "The POKéMON LEAGUE's rules state\n"
	.string "that TRAINERS are to be given this\l"
	.string "if they defeat a GYM LEADER.\p"
	.string "Please accept the official POKéMON\n"
	.string "LEAGUE Ember BADGE.$"

HozuniCity_Gym_Text_ReceivedEmberBadge:
	.string "{PLAYER} received the EMBER BADGE\n"
	.string "from BLAZE.$"

HozuniCity_Gym_Text_EmberBadgeInfoTakeThis:
	.string "The EMBER BADGE heightens the SP. ATTACK\n"
	.string "power of your POKéMON.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "Please take this with you, too.$"

HozuniCity_Gym_Text_ExplainFireSpin:
	.string "That TECHNICAL MACHINE, TM25,\n"
	.string "contains FIRE SPIN.\p"
	.string "It not only inflicts damage by hitting\n"
	.string "your opponent with a ring of fire,\p"
	.string "it also traps them for a few turns!\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a POKéMON.\p"
	.string "Remember, a TM can be used only once,\n"
	.string "so think before you use it.$"

HozuniCity_Gym_Text_BlazePostBattle:
	.string "Have you considered challenging other\n"
	.string "GYM LEADERS, since you are so strong!\p"
	.string "By battling many TRAINERS, you can\n"
	.string "learn many things.$"

HozuniCity_Gym_Text_GymStatue:
	.string "HOZUNI CITY POKéMON GYM$"

HozuniCity_Gym_Text_GymStatueCertified:
	.string "HOZUNI CITY POKéMON GYM\p"
	.string "BLAZE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

HozuniCity_Gym_Text_FelicityIntro:
	.string "Don't go easy on me just because\n"
	.string "I'm a girl... I promise I'm tougher\l"
	.string "than I look!$"

HozuniCity_Gym_Text_FelicityDefeat:
	.string "Wow! What a blast!$"

HozuniCity_Gym_Text_FelicityDefeated:
	.string "You're really good at POKéMON battling,\n"
	.string "you know.\p"
	.string "You should try collecting all eight GYM\n"
	.string "badges and challenging the ELITE FOUR.$"
