HozuniCity_House2_MapScripts::
	.byte 0

HozuniCity_House2_EventScript_OldWoman::
	goto_if_unset FLAG_RECEIVED_QUICK_CLAW, HozuniCity_House2_EventScript_GiveQuickClaw
	msgbox HozuniCity_House2_Text_OldWoman, MSGBOX_NPC
	end

HozuniCity_House2_EventScript_GiveQuickClaw::
	lock
	faceplayer
	msgbox HozuniCity_House2_Text_GiveQuickClaw, MSGBOX_NPC
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox HozuniCity_House2_Text_GiveQuickClaw2, MSGBOX_NPC
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end


HozuniCity_House2_Text_GiveQuickClaw:
	.string "When I was younger I used to be quite\n"
	.string "the trainer too, you know.\p"
	.string "Here, take this. I have no use of it\n" 
	.string "anymore.$"

HozuniCity_House2_Text_GiveQuickClaw2:
	.string "That's a QUICK CLAW. If you let your\n"
	.string "POKéMON hold it, sometimes it will\p"
	.string "occasionally speed up and get to move\n"
	.string "before its opponent.$"

HozuniCity_House2_Text_OldWoman:
	.string "My ancestors have lived in this city\n"
	.string "since time immemorial.\p"
	.string "I wonder what it will be like\n"
	.string "when I'm gone, too.$"
