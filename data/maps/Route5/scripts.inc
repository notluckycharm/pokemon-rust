Route5_MapScripts::
	.byte 0
	
Route5_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route5_Text_HectorIntro, Route5_Text_HectorDefeat
	msgbox Route5_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route5_EventScript_Ichirou::
	trainerbattle_single TRAINER_ICHIROU, Route5_Text_IchirouIntro, Route5_Text_IchirouDefeat
	msgbox Route5_Text_IchirouPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route5_EventScript_Ed::
	trainerbattle_single TRAINER_ED, Route5_Text_EdIntro, Route5_Text_EdDefeat
	msgbox Route5_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route5_EventScript_Chuck::
	trainerbattle_single TRAINER_CHUCK, Route5_Text_ChuckIntro, Route5_Text_ChuckDefeat
	msgbox Route5_Text_ChuckPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route5_Text_IchirouIntro:
	.string "Ninja attaaaaaaaaaaaaaaaaack!$"

Route5_Text_IchirouDefeat:
	.string "Even a surprise attack didn't help me!$"

Route5_Text_IchirouPostBattle:
	.string "I'm not a real ninja yet,\n"
	.string "but I will be one day!$"

Route5_Text_EdIntro:
	.string "I'm training to take on the HOZUNI CITY\n"
	.string "gym. Care to join me?$"

Route5_Text_EdDefeat:
	.string "That's not how I planned it to go...$"

Route5_Text_EdPostBattle:
	.string "Sometimes I come here to clear\n"
	.string "my head and go for a nice run.$"

Route5_Text_ChuckIntro:
	.string "Hoho! A fellow traveler!\n"
	.string "Care for a battle to make the journey\l"
	.string "a bit less dull?$"

Route5_Text_ChuckDefeat:
	.string "I think I got some sand in my eye.$"

Route5_Text_ChuckPostBattle:
	.string "Be careful when battling POKéMON in\n"
	.string "a sandstorm. All POKéMON except STEEL\l"
	.string "and ROCK types will take damage every turn.$"

Route5_Text_HectorIntro:
	.string "I'm exhausted from the heat.\n"
	.string "Maybe a POKéMON BATTLE will cool me down$"

Route5_Text_HectorDefeat:
	.string "I lost...\n"
	.string "I think the heat is getting to me.$"

Route5_Text_HectorPostBattle:
	.string "This area supposedly used to be a green\n"
	.string "paradise in ancient times.\p"
	.string "That's what I learned in school, anyways.$"