Route1_MapScripts::
	.byte 0

Route1_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route1_Text_CoraIntro, Route1_Text_CoraDefeated
	msgbox Route1_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_Text_CoraIntro:
	.string "When two trainer's eyes meet...\n"
	.string "That's when a POKéMON BATTLE begins!$"

Route1_Text_CoraDefeated:
	.string "Wow, you're tough!$"

Route1_Text_CoraPostBattle:
	.string "If you want to avoid a battle,\n"
	.string "make sure to not get in another\p"
	.string "trainer's view!$"