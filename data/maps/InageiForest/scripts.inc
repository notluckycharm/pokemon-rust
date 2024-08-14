.set NIGHT_LOW, 7
.set NIGHT_HIGH, 20

InageiForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, InageiForest_OnTransition
	.byte 0

InageiForest_OnTransition::
	gettime
	goto_if_le VAR_0x8000, NIGHT_LOW, InageiForest_SetNightEncounter
	goto_if_ge VAR_0x8000, NIGHT_HIGH, InageiForest_SetNightEncounter
	setvar VAR_INAGEI_FOREST_WILD_SET, 0
	end

InageiForest_EncounterSet_0::
	gettime
	goto_if_le VAR_0x8000, NIGHT_LOW, InageiForest_SetNightEncounter
	goto_if_ge VAR_0x8000, NIGHT_HIGH, InageiForest_SetNightEncounter
	setvar VAR_INAGEI_FOREST_WILD_SET, 0
	end

InageiForest_EncounterSet_1::
	gettime
	goto_if_le VAR_0x8000, NIGHT_LOW, InageiForest_SetNightEncounter
	goto_if_ge VAR_0x8000, NIGHT_HIGH, InageiForest_SetNightEncounter
	setvar VAR_INAGEI_FOREST_WILD_SET, 1
	end

InageiForest_EncounterSet_3::
	gettime
	goto_if_le VAR_0x8000, NIGHT_LOW, InageiForest_SetNightEncounter
	goto_if_ge VAR_0x8000, NIGHT_HIGH, InageiForest_SetNightEncounter
	setvar VAR_INAGEI_FOREST_WILD_SET, 3
	end

InageiForest_SetNightEncounter::
	setvar VAR_INAGEI_FOREST_WILD_SET, 4
	end

InageiForest_EventScript_Cassio::
	trainerbattle_single TRAINER_CASSIO, InageiForest_Text_CassioIntro, InageiForest_Text_CassioDefeated
	msgbox InageiForest_Text_CassioPostBattle, MSGBOX_AUTOCLOSE
	end

InageiForest_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, InageiForest_Text_LeahIntro, InageiForest_Text_LeahDefeated
	msgbox InageiForest_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

InageiForest_EventScript_Alfonso::
	trainerbattle_single TRAINER_ALFONSO, InageiForest_Text_AlfonsoIntro, InageiForest_Text_AlfonsoDefeated
	msgbox InageiForest_Text_AlfonsoPostBattle, MSGBOX_AUTOCLOSE
	end

InageiForest_EventScript_Bonnie::
	trainerbattle_single TRAINER_BONNIE, InageiForest_Text_BonnieIntro, InageiForest_Text_BonnieDefeated
	msgbox InageiForest_Text_BonniePostBattle, MSGBOX_AUTOCLOSE
	end

InageiForest_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE, InageiForest_Text_ClydeIntro, InageiForest_Text_ClydeDefeated
	msgbox InageiForest_Text_ClydePostBattle, MSGBOX_AUTOCLOSE
	end

InageiForest_Text_CassioIntro:
	.string "Try and beat my BUG-type POKéMON!\n"
	.string "I bet you can't do it!$"

InageiForest_Text_CassioDefeated:
	.string "Wow, you're really strong.$"

InageiForest_Text_CassioPostBattle:
	.string "They say deep in INAGEI FOREST\n"
	.string "a super rare POKéMON makes its nest.\p"
	.string "I wonder if I'll ever come across it.$"


InageiForest_Text_LeahIntro:
	.string "I may be young but you better not\n"
	.string "go easy on me!$"

InageiForest_Text_LeahDefeated:
	.string "I need to train my POKéMON more!$"

InageiForest_Text_LeahPostBattle:
	.string "GRASS-type POKéMON are the best!\p"
	.string "They're weak to FIRE and BUG type\n"
	.string "POKéMON, though.$"

InageiForest_Text_AlfonsoIntro:
	.string "My FLYING-type POKéMON need to strech\n"
	.string "their wings.\p"
	.string "Care to battle?$"

InageiForest_Text_AlfonsoDefeated:
	.string "Down all the way to the ground!$"

InageiForest_Text_AlfonsoPostBattle:
	.string "I always keep the POKéMON that I\n"
	.string "want to use together in a\l"
	.string "DOUBLE BATTTLE in the front of my party.$"

InageiForest_Text_BonnieIntro:
	.string "My teacher told me to go find rare\n"
	.string "POKéMON in INAGEI FOREST\p"
	.string "What POKéMON have you got?$"

InageiForest_Text_BonnieDefeated:
	.string "Urf, I've been beat.$"

InageiForest_Text_BonniePostBattle:
	.string "I'm the only girl in my class who\n"
	.string "prefers BUG-type POKéMON\p"
	.string "They're so cool!$"

InageiForest_Text_ClydeIntro:
	.string "I'm looking for the BEAST of\n"
	.string "INAGEI FOREST.\p"
	.string "Do you know where it is?$"

InageiForest_Text_ClydeDefeated:
	.string "I wasn't ready!$"

InageiForest_Text_ClydePostBattle:
	.string "I'm on a mission to catch the rarest\n"
	.string "POKéMON in LACOTIA.\p"
	.string "You should give it a try, too.$"