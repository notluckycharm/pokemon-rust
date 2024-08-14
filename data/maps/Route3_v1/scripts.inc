Route3_v1_MapScripts::
	.byte 0

Route3_v1_EventScript_Marian::
	trainerbattle_single TRAINER_MARIAN, Route3_v1_Text_MarianIntro, Route3_v1_Text_MarianDefeated
	msgbox Route3_v1_Text_MarianPostBattle, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route3_v1_Text_MarianPostBattle2, MSGBOX_AUTOCLOSE
	end

Route3_v1_Text_MarianIntro:
	.string "Oh! A weary traveler.\n"
	.string "Would you like to heal your POKéMON?\p"
	.string "How about a battle first?$"

Route3_v1_Text_MarianDefeated:
	.string "What a thrill!$"

Route3_v1_Text_MarianPostBattle:
	.string "Your POKéMON look exhausted!\p"
	.string "Let me heal them right up.$"

Route3_v1_Text_MarianPostBattle2:
	.string "Be careful not to push your POKéMON\n"
	.string "too hard, OK?$"