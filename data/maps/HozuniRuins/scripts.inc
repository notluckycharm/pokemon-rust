HozuniRuins_MapScripts::
	.byte 0

HozuniRuins_EventScript_Blaze::
	goto_if_eq VAR_HOZUNI_CITY_STATE, 0, HozuniRuins_EventScript_BlazeBusy
	goto_if_eq VAR_HOZUNI_CITY_STATE, 1, HozuniRuins_EventScript_BlazeBusy
	msgbox HozuniRuins_Text_Blaze, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	removeobject 1
	setvar VAR_HOZUNI_CITY_STATE, 3
	fadescreen FADE_FROM_BLACK
	release
	end

HozuniRuins_EventScript_BlazeBusy::
	msgbox HozuniRuins_Text_BlazeBusy, MSGBOX_AUTOCLOSE
	end

HozuniRuins_Text_BlazeBusy:
	.string "...\p"
	.string "...\p"
	.string "... Now where did I put that thing?$"

HozuniRuins_Text_Blaze:
	.string "Oh, you found the fossil I was looking for.\n"
	.string "Thanks for picking it up!\l"
	.string "I thought I had lost it\p"
	.string "Oh, don't worry, you can keep it. I have\n"
	.string "plenty.\p"
	.string "Sorry for not giving you a proper welcome at\n"
	.string "the HOZUNI CITY GYM.\l" 
	.string "I can be a bit scatterbrained.\p"
	.string "You should drop by and challenge me to a\n"
	.string "battle.\l"
	.string "I'd love to see what you got!$"