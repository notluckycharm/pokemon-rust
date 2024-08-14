HozuniCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HozuniCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


HozuniCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_HOZUNI_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

HozuniCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
	