Route2_MapScripts::
	.byte 0

Route2_EventScript_Cheyenne::
	trainerbattle_single TRAINER_CHEYENNE, Route2_Text_CheyenneIntro, Route2_Text_CheyenneDefeated
	msgbox Route2_Text_CheyennePostBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND, Route2_Text_RaymondIntro, Route2_Text_RaymondDefeated
	msgbox Route2_Text_RaymondPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Trevor::
	trainerbattle_single TRAINER_TREVOR, Route2_Text_TrevorIntro, Route2_Text_TrevorDefeated
	msgbox Route2_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_Text_CheyenneIntro:
	.string "Hiya!\n"
	.string "Let me show you the cool POKéMON I\l"
	.string "found!$"

Route2_Text_CheyenneDefeated:
	.string "Oof, I should have trained\n"
	.string "my POKéMON a bit more!$"

Route2_Text_CheyennePostBattle:
	.string "Freshly caught POKéMON are\n"
	.string "always weaker than trained ones.\p"
	.string "Even if they're the same level!$"

Route2_Text_RaymondIntro:
	.string "Take a good look at my super strong\n"
	.string "ROCK type POKéMON!$"

Route2_Text_RaymondDefeated:
	.string "My precious POKéMON need a break.$"

Route2_Text_RaymondPostBattle:
	.string "ROCK type POKéMON are \n"
	.string "SUPER-EFFECTIVE against\l"
	.string "BUG-type POKéMON, you know.$"

Route2_Text_TrevorIntro:
	.string "Hey you have POKéMON!\n"
	.string "Let's battle!$"

Route2_Text_TrevorDefeated:
	.string "Agh, I lost.$"

Route2_Text_TrevorPostBattle:
	.string "BUG-type POKéMON scare me.\n"
	.string "That's why I can't go into\l"
	.string "INAGEI FOREST.$"