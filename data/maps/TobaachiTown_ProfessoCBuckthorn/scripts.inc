TobaachiTown_ProfessoCBuckthorn_MapScripts::
	.byte 0

TobaachiTown_CBuckthorn_PokeballTeddiursa::
	goto_if_set FLAG_MET_PROF_BUCKTHORN, TobaachiTown_HeroHouse_2F_GetTeddiursa
	goto Script_TobaachiTown_HeroHouse_2F_TeddiursaStillThere
	end

TobaachiTown_CBuckthorn_PokeballClefairy::
	goto_if_set FLAG_MET_PROF_BUCKTHORN, TobaachiTown_HeroHouse_2F_GetClefairy
	goto Script_TobaachiTown_HeroHouse_2F_ClefairyStillThere
	end

TobaachiTown_CBuckthorn_PokeballSnubbull::
	goto_if_set FLAG_MET_PROF_BUCKTHORN, TobaachiTown_HeroHouse_2F_GetSnubbull
	goto Script_TobaachiTown_HeroHouse_2F_SnubbullStillThere
	end

TobaachiTown_CBuckthorn_EventScript_GivePokedexMission::
	lock
	applymovement 4, TobaachiTown_CBuckthorn_Movement_GivePokedex
	waitmovement 4
	msgbox TobaachiTown_CBuckthorn_Text_PokedexMission, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_STARTER
	release
	end

TobaachiTown_CBuckthorn_Movement_GivePokedex::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

TobaachiTown_HeroHouse_2F_GetTeddiursa::
	lock
	faceplayer
	goto_if_set FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_SNUBBULL, Script_TobaachiTown_HeroHouse_2F_TeddiursaStillThere
	goto_if_set FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_CLEFAIRY, Script_TobaachiTown_HeroHouse_2F_TeddiursaStillThere
	showmonpic SPECIES_TEDDIURSA, 10, 3
	msgbox TobaachiTown_HeroHouse_2F_Text_YoullTakeTeddiura, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TobaachiTownTown_HeroHouse_2F_EventScript_TakeYourTime
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq Script_PlayerHasFullParty
	goto TobaachiTown_HeroHouse_2F_GiveTeddiursa
	setflag FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_TEDDIURSA
	release
	end

TobaachiTown_HeroHouse_2F_GetSnubbull::
	lock
	faceplayer
	goto_if_set FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_TEDDIURSA, Script_TobaachiTown_HeroHouse_2F_SnubbullStillThere
	goto_if_set FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_CLEFAIRY, Script_TobaachiTown_HeroHouse_2F_SnubbullStillThere
	showmonpic SPECIES_SNUBBULL, 10, 3
	msgbox TobaachiTown_HeroHouse_2F_Text_YoullTakeSnubbull, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TobaachiTownTown_HeroHouse_2F_EventScript_TakeYourTime
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq Script_PlayerHasFullParty
	goto TobaachiTown_HeroHouse_2F_GiveSnubbull
	setflag FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_SNUBBULL
	release
	end

TobaachiTown_HeroHouse_2F_GetClefairy::
	lock
	faceplayer
	goto_if_set FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_TEDDIURSA, Script_TobaachiTown_HeroHouse_2F_ClefairyStillThere
	goto_if_set FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_SNUBBULL, Script_TobaachiTown_HeroHouse_2F_ClefairyStillThere
	showmonpic SPECIES_CLEFAIRY, 10, 3
	msgbox TobaachiTown_HeroHouse_2F_Text_YoullTakeClefairy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TobaachiTownTown_HeroHouse_2F_EventScript_TakeYourTime
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq Script_PlayerHasFullParty
	goto TobaachiTown_HeroHouse_2F_GiveClefairy
	setflag FLAG_TOBAACHI_TOWN_HEROHOUSE_2F_CLEFAIRY
	release
	end

Script_PlayerHasFullParty::
	msgbox Text_PlayerHasFullParty, MSGBOX_DEFAULT
	hidemonpic
	release
	end

TobaachiTown_HeroHouse_2F_GiveTeddiursa::
	setflag FLAG_SYS_POKEMON_GET
	bufferspeciesname STR_VAR_1, SPECIES_TEDDIURSA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TEDDIURSA
	playfanfare 370
	givemon SPECIES_TEDDIURSA, 5
	waitfanfare
	hidemonpic
	removeobject 1
	release
	goto TobaachiTown_CBuckthorn_EventScript_GivePokedexMission
	end

TobaachiTown_HeroHouse_2F_GiveSnubbull::
	setflag FLAG_SYS_POKEMON_GET
	bufferspeciesname STR_VAR_1, SPECIES_SNUBBULL
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SNUBBULL
	playfanfare 370
	givemon SPECIES_SNUBBULL, 5
	waitfanfare
	hidemonpic
	removeobject 3
	release
	goto TobaachiTown_CBuckthorn_EventScript_GivePokedexMission
	end

TobaachiTown_HeroHouse_2F_GiveClefairy::
	setflag FLAG_SYS_POKEMON_GET
	bufferspeciesname STR_VAR_1, SPECIES_CLEFAIRY
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CLEFAIRY
	playfanfare 370
	givemon SPECIES_CLEFAIRY, 5
	waitfanfare
	hidemonpic
	removeobject 2
	release
	goto TobaachiTown_CBuckthorn_EventScript_GivePokedexMission
	end


TobaachiTownTown_HeroHouse_2F_EventScript_TakeYourTime::
	hidemonpic
	msgbox TobaachiTown_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

Script_TobaachiTown_HeroHouse_2F_TeddiursaStillThere::
	msgbox TobaachiTown_HeroHouse_2F_Text_Teddiursa_StillThere, MSGBOX_DEFAULT
	releaseall
	end

Script_TobaachiTown_HeroHouse_2F_SnubbullStillThere::
	msgbox TobaachiTown_HeroHouse_2F_Text_Snubbull_StillThere, MSGBOX_DEFAULT
	releaseall
	end

Script_TobaachiTown_HeroHouse_2F_ClefairyStillThere::
	msgbox TobaachiTown_HeroHouse_2F_Text_Clefairy_StillThere, MSGBOX_DEFAULT
	releaseall
	end

TobaachiTown_ProfCBuckthorn_EventScript_Interact::
	goto_if_set FLAG_ADVENTURE_STARTED, TobaachiTown_ProfCBuckthorn_EventScript_CheckPokedex
	checkitem ITEM_PARCEL
	compare VAR_RESULT, 1
	goto_if_ge TobaachiTown_ProfCBuckthorn_EventScript_GivePokedex
	goto_if_set FLAG_RECEIVED_STARTER, TobaachiTown_ProfCBuckthorn_EventScript_Interact2
	lock
	faceplayer
	msgbox TobaachiTown_ProfCBuckthorn_Text_Interact, MSGBOX_DEFAULT
	setflag FLAG_MET_PROF_BUCKTHORN
	releaseall
	end
	 
TobaachiTown_ProfCBuckthorn_EventScript_Interact2::
	checkitem ITEM_PARCEL
	compare VAR_RESULT, 1
	goto_if_ge TobaachiTown_ProfCBuckthorn_EventScript_GivePokedex
	lock
	msgbox TobaachiTown_CBuckthorn_Text_PokedexMission, MSGBOX_DEFAULT
	releaseall
	end
	
TobaachiTown_ProfCBuckthorn_EventScript_GivePokedex::
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox TobaachiTown_CBuckthorn_Text_GivePokedex, MSGBOX_NPC
	playfanfare 370
	msgbox TobaachiTown_CBuckthorn_Text_ReceivedPokedex, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	msgbox TobaachiTown_CBuckthorn_Text_GivePokedex2, MSGBOX_NPC
	msgbox TobaachiTown_CBuckthorn_Text_GivePokedex3, MSGBOX_NPC
	giveitem ITEM_POKE_BALL, 5
	removeitem ITEM_PARCEL
	releaseall
	end

TobaachiTown_ProfCBuckthorn_EventScript_CheckPokedex::
	lock
	faceplayer
	msgbox TobaachiTown_CBuckthorn_Text_GivePokedex4, MSGBOX_NPC
	releaseall
	end

TobaachiTown_CBuckthorn_Text_GivePokedex:
	.string "PROF. BUCKTHORN: Ah, {PLAYER}.\n"
	.string "How is your {STR_VAR_1}?\p"
	.string "It looks like it's taking a liking\n"
	.string "to you\p"
	.string "Oh?\n"
	.string "I see you got my SPECIAL PACKAGE\p"
	.string "It's actually for you:\n"
	.string "It's a POKéDEX!$"

TobaachiTown_CBuckthorn_Text_GivePokedex2:
	.string "The POKéDEX is a\n"
	.string "high-tec tool that automatically\l"
	.string "makes a record of any POKéMON you\l"
	.string "meet or catch!\p"
	.string "When I was your age, I studied\n"
	.string "POKéMON linguistics.\p"
	.string "I used to use my POKéDEX to collect\n"
	.string "information about every rare POKéMON\l"
	.string "I met!\p"
	.string "If you wouldn't mind, I'd like for you\n"
	.string "to do the same! Try to catch as many\l"
	.string "POKéMON as you can!$"

TobaachiTown_CBuckthorn_Text_GivePokedex3:
	.string "Oh, and take these POKéBALLS.\p"
	.string "You can use them to capture\n"
	.string "a POKéMON once you've lowered its health.$"

TobaachiTown_CBuckthorn_Text_GivePokedex4:
	.string "PROF BUCKTHORN: How's your POKéDEX\l"
	.string "going, {PLAYER}?$"

TobaachiTown_CBuckthorn_Text_PokedexMission:
	.string "PROF. BUCKTHORN: One more thing.\p"
	.string "A colleague of mine has a package\n"
	.string "waiting for me in AURIGA TOWN.\p"
	.string "Get it for me, won't you?$"

TobaachiTown_ProfCBuckthorn_Text_Interact:
	.string "PROF. BUCKTHORN: Oh! You startled me.\n"
	.string "I've been expecting you for quite\l some time, {PLAYER}.\p"
	.string "I recieved your POKéMON TRAINER \n"
	.string "application, and everything seems to be\p"
	.string "in order.\p"
	.string "On my desk there are three POKÉMON.\n"
	.string "Take your pick!$"

TobaachiTown_Text_TakeYourTimeAllInvaluable:
	.string "PROF. BUCKTHORN: Take your time before\n"
	.string "you decide.$"

TobaachiTown_HeroHouse_2F_Text_YoullTakeTeddiura:
	.string "PROF. BUCKTHORN: The LITTLE BEAR\n"
	.string "POKéMON TEDDIURSA is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the TEDDIURSA?$"

TobaachiTown_HeroHouse_2F_Text_YoullTakeSnubbull:
	.string "PROF. BUCKTHORN: The FAIRY POKéMON\n"
	.string "SNUBBULL is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the SNUBBULL?$"

TobaachiTown_HeroHouse_2F_Text_YoullTakeClefairy:
	.string "PROF. BUCKTHORN: The FAIRY POKéMON\n"
	.string "CLEFAIRY is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the CLEFAIRY?$"

Text_PlayerHasFullParty:
.string "Ah, your party is full.$"

TobaachiTown_HeroHouse_2F_Text_Teddiursa_StillThere:
	.string "It's a Pokéball containing\n"
	.string "a TEDDIURSA.$"

TobaachiTown_HeroHouse_2F_Text_Snubbull_StillThere:
	.string "It's a Pokéball containing\n"
	.string "a SNUBBULL.$"

TobaachiTown_HeroHouse_2F_Text_Clefairy_StillThere:
	.string "It's a Pokéball containing\n"
	.string "a CLEFAIRY.$"

TobaachiTown_CBuckthorn_Text_ReceivedPokedex:
	.string "{PLAYER} received a POKéDEX!$"
