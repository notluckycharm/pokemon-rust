NoagaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NoagaTown_OnTransition
	.byte 0

NoagaTown_OnTransition::
	setflag FLAG_VISITED_NOAGA_TOWN
	end

NoagaTown_EventScript_Scientist::
	setflag FLAG_SYS_QUEST_MENU_GET
	msgbox NoagaTown_Text_Quest, MSGBOX_AUTOCLOSE
	release
	end

NoagaTown_Text_Quest:
	.string "Quests enabled.$"
	