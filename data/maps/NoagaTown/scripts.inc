NoagaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NoagaTown_OnTransition
	.byte 0

NoagaTown_OnTransition::
	setflag FLAG_VISITED_NOAGA_TOWN
	end