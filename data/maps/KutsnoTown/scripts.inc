KutsnoTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KutsnoTown_OnTransition
	.byte 0

KutsnoTown_OnTransition::
	setflag FLAG_VISITED_KUTSNO_TOWN
	end