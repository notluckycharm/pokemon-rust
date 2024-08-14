AurigaTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AurigaTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


AurigaTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_AURIGA_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

AurigaTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
	