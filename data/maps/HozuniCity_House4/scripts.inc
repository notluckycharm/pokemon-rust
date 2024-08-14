HozuniCity_House4_MapScripts::
	.byte 0

HozuniCity_House4_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, HozuniCity_House4_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SNORUNT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox HozuniCity_House4_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, HozuniCity_House4_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, HozuniCity_House4_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, HozuniCity_House4_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox HozuniCity_House4_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

HozuniCity_House4_EventScript_DeclineTrade::
	msgbox HozuniCity_House4_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

HozuniCity_House4_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox HozuniCity_House4_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

HozuniCity_House4_EventScript_TradeCompleted::
	msgbox HozuniCity_House4_Text_GoingToMakePanpourStrong, MSGBOX_DEFAULT
	release
	end

HozuniCity_House4_Text_YouWillTradeWontYou:
	.string "I fear my plants are wilting\n"
	.string "from the heat in HOZUNI CITY!\p"
	.string "I'll do anything for a WATER-type\n"
	.string "POKéMON like {STR_VAR_1}!\p"
	.string "If you have one, will you trade\n"
	.string "your {STR_VAR_1} for my {STR_VAR_2}?$"

HozuniCity_House4_Text_MonYouTakeCare:
	.string "{STR_VAR_1}, welcome!\n"
	.string "{STR_VAR_2}, you take care!$"

HozuniCity_House4_Text_ThisIsntAMon:
	.string "Oh, this won't do.\n"
	.string "That isn't a {STR_VAR_1}.$"

HozuniCity_House4_Text_YouWontTradeMe:
	.string "No? You won't trade me?\n"
	.string "Well, come back if you change your mind.$"

HozuniCity_House4_Text_GoingToMakePanpourStrong:
	.string "I'm going to take good care of\n"
	.string "PANPOUR from this moment on!\p"
	.string "I hope you do the same with SNORUNT!$"

HozuniCity_House4_Text_TradingMemoriesWithOthers:
	.string "Trading POKéMON with others…\p"
	.string "It's as if you're trading your own\n"
	.string "memories with other people.$"
