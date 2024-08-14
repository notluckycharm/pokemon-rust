HozuniCity_PokemonSchool_MapScripts::
	.byte 0

HozuniCity_EventScript_SchoolTeacher::
	goto_if_eq VAR_HOZUNI_CITY_STATE, 1, HozuniCity_PokemonSchool_EventScript_BlazeNotHereEither
	goto_if_eq VAR_HOZUNI_CITY_STATE, 2, HozuniCity_PokemonSchool_EventScript_WhereBlazeWent
	msgbox HozuniCity_Text_SchoolTeacher, MSGBOX_NPC
	release
	end

HozuniCity_PokemonSchool_EventScript_WhereBlazeWent::
	msgbox HozuniCity_PokemonSchool_Text_WhereBlazeWent, MSGBOX_NPC
	release
	end

HozuniCity_EventScript_GiveRootFossil::
	setvar VAR_0x8004, ITEM_ROOT_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveDomeFossil::
	setvar VAR_0x8004, ITEM_DOME_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveOldAmberFossil::
	setvar VAR_0x8004, ITEM_OLD_AMBER
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveHelixFossil::
	setvar VAR_0x8004, ITEM_HELIX_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveArmorFossil::
	setvar VAR_0x8004, ITEM_ARMOR_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveSkullFossil::
	setvar VAR_0x8004, ITEM_SKULL_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveCoverFossil::
	setvar VAR_0x8004, ITEM_COVER_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GivePlumeFossil::
	setvar VAR_0x8004, ITEM_PLUME_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveJawFossil::
	setvar VAR_0x8004, ITEM_JAW_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveSailFossil::
	setvar VAR_0x8004, ITEM_SAIL_FOSSIL
	goto HozuniCity_EventScript_GiveFossil
	return

HozuniCity_EventScript_GiveFossil::
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox HozuniCity_PokemonSchool_Text_WhereBlazeWent, MSGBOX_AUTOCLOSE
	release
	end

HozuniCity_PokemonSchool_EventScript_BlazeNotHereEither::
	setvar VAR_HOZUNI_CITY_STATE, 2
	msgbox HozuniCity_PokemonSchool_Text_BlazeNotHereEither, MSGBOX_NPC
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
	switch VAR_RESULT
	case 0, HozuniCity_EventScript_GiveRootFossil
	case 5, HozuniCity_EventScript_GiveDomeFossil
	case 1, HozuniCity_EventScript_GiveOldAmberFossil
	case 6, HozuniCity_EventScript_GiveHelixFossil
	case 2, HozuniCity_EventScript_GiveArmorFossil
	case 7, HozuniCity_EventScript_GiveSkullFossil
	case 3, HozuniCity_EventScript_GiveCoverFossil
	case 8, HozuniCity_EventScript_GivePlumeFossil
	case 4, HozuniCity_EventScript_GiveJawFossil
	case 9, HozuniCity_EventScript_GiveSailFossil
	release
	end

HozuniCity_PokemonSchool_EventScript_SchoolBoy::
	msgbox HozuniCity_PokemonSchool_Text_SchoolBoy, MSGBOX_NPC
	release
	end

HozuniCity_PokemonSchool_EventScript_SchoolBoy2::
	msgbox HozuniCity_PokemonSchool_Text_SchoolBoy2, MSGBOX_NPC
	release
	end

HozuniCity_PokemonSchool_EventScript_GamerBoy1::
	msgbox HozuniCity_PokemonSchool_Text_GamerBoy1, MSGBOX_DEFAULT
	release
	end

HozuniCity_PokemonSchool_EventScript_GamerBoy2::
	msgbox HozuniCity_PokemonSchool_Text_GamerBoy2, MSGBOX_DEFAULT
	release
	end

HozuniCity_PokemonSchool_EventScript_SchoolGirl1::
	msgbox HozuniCity_PokemonSchool_Text_SchoolGirl1, MSGBOX_NPC
	release
	end

HozuniCity_PokemonSchool_EventScript_SchoolBoy3::
	lock
	faceplayer
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, PokemonSchool_EventScript_SchoolBoy3Defeated
	msgbox HozuniCity_PokemonSchool_Text_SchoolBoy3_OfferBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PokemonSchool_EventScript_DeclinedBattle
	goto PokemonSchool_Battle_SchoolBoy3
	end


PokemonSchool_Battle_SchoolBoy3::
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
	trainerbattle_single TRAINER_ROLAND, PokemonSchool_Text_RolandIntro, PokemonSchool_Text_RolandDefeated
	msgbox PokemonSchool_Text_RolandDefeated, MSGBOX_DEFAULT
	end

PokemonSchool_EventScript_SchoolBoy3Defeated::
	msgbox PokemonSchool_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	release
	end

PokemonSchool_EventScript_DeclinedBattle::
	msgbox HozuniCity_PokemonSchool_DeclinedBattle, MSGBOX_NPC
	release
	end


HozuniCity_PokemonSchool_Text_GamerBoy1:
	.string "...\p"
	.string "Can you move? I'm trying to trade POKéMON\n"
	.string "with my friend.$"

HozuniCity_PokemonSchool_Text_GamerBoy2:
	.string "...\p"
	.string "What POKéMON do you think I should trade for\n"
	.string "a SPEAROW?$"

PokemonSchool_Text_RolandIntro:
	.string "All right! Let me show you what I learned!$"

PokemonSchool_Text_RolandDefeated:
	.string "Guess I need to study a bit harder.$"

PokemonSchool_Text_RolandPostBattle:
	.string "In the LACOCIA region, double battles are\n"
	.string "popular among trainers.\p"
	.string "Their strategy differs a lot from regular,\n"
	.string "single battles!$"

HozuniCity_PokemonSchool_DeclinedBattle:
	.string "C'mon! How else am I supposed to learn?\n$"

HozuniCity_PokemonSchool_Text_SchoolBoy3_OfferBattle:
	.string "They say doing is the best way to learn.\p"
	.string "Can I try out the new skills I learned\n"
	.string "by battling you?$"

HozuniCity_PokemonSchool_Text_SchoolBoy2:
	.string "Everything I need to know about POKéMON\n"
	.string "battles is right here in my textbook.$"

HozuniCity_PokemonSchool_Text_SchoolBoy:
	.string "FIRE type POKéMON are weak to\n"
	.string "WATER type POKéMON. WATER type\p"
	.string "POKéMON are weak to GRASS type\n"
	.string "POKéMON. And GRASS type POKéMON\l"
	.string "are weak to FIRE type POKéMON!\p"
	.string "Argh, I'll never get the hang of\n"
	.string "type match-ups!$"

HozuniCity_PokemonSchool_Text_SchoolGirl1:
	.string "POKéMON by nature know how to use\n"
	.string "held items like berries in a pinch.\p"
	.string "But, they won't know how to use\n"
	.string "man-made items like potions!$"

HozuniCity_PokemonSchool_Text_BlazeNotHereEither:
	.string "Hello there! Are you here to learn about\n"
	.string "what it takes to be a POKéMON trainer?\p"
	.string "...\p"
	.string "...\p"
	.string "Oh, you're looking for BLAZE.\n"
	.string "He ran through here earlier.\p"
	.string "He was in such a hurry talking about his\n"
	.string "theories that he left this behind.\p"
	.string "Can you take it to him for me?$"
	
HozuniCity_PokemonSchool_Text_WhereBlazeWent:
	.string "Blaze said he was running off to the old\n"
	.string "HOZUNI RUINS.\p"
	.string "You can get there by going through\n"
	.string "ROUTE 5.$"

HozuniCity_Text_SchoolTeacher:
	.string "Hello there! Are you here to learn about\n"
	.string "what it takes to be a POKéMON trainer?\p"
	.string "Chapter One of what you need to know\n"
	.string "is on the blackboard behind me.$"