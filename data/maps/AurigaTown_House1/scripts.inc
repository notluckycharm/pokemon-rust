AurigaTown_House1_MapScripts::
	.byte 0

AurigaTown_House1_EventScript_Man::
	lock
	faceplayer
	msgbox AurigaTown_House1_Text_Man, MSGBOX_NPC
	release
	end


AurigaTown_House1_Eventscript_Prof2::
	lock
	faceplayer
	msgbox AurigaTown_House1_Text_Prof2, MSGBOX_NPC
	releaseall
	end

AurigaTown_House1_EventScript_Prof::
	checkitem ITEM_PARCEL
	goto_if_eq VAR_RESULT, TRUE, AurigaTown_House1_Eventscript_Prof2
	goto_if_set FLAG_ADVENTURE_STARTED, AurigaTown_House1_Eventscript_Prof2
	lock
	faceplayer
	msgbox AurigaTown_House1_Text_Prof, MSGBOX_NPC
	giveitem ITEM_PARCEL
	setflag FLAG_RECEIVED_SPECIAL_PACKAGE
	release
	return

AurigaTown_House1_Text_Man:
	.string "Wild POKéMON love the berries that grow\n"
	.string "around AURIGA TOWN. Try picking some\l"
	.string "for your journey.$"

AurigaTown_House1_Text_Prof:
	.string "You must be {PLAYER}.\n"
	.string "PROF. BUCKTHORN told me you'd be coming\p"
	.string "to pick up a SPECIAL PACKAGE.\p"
	.string "Make sure it gets back safe, OK?$"

AurigaTown_House1_Text_Prof2:
	.string "Professor Buckthorn and I go way back.\n"
	.string "He used to be quite the trainer himself,\l you know.$"