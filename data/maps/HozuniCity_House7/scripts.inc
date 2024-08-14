HozuniCity_House7_MapScripts::
	.byte 0

HozuniCity_House7_EventScript_EggLady::
	lock
	faceplayer
	msgbox HozuniCity_House7_Text_EggLady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, HozuniCity_House7_EventScript_NoEgg
	goto HozuniCity_House7_EventScript_EggLady_CheckForCoupon
	end

HozuniCity_House7_EventScript_EggLady_CheckForCoupon::
	checkitem ITEM_EGG_COUPON
	goto_if_eq VAR_RESULT, FALSE, HozuniCity_House7_EventScript_NoCoupon
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq EggLady_Script_PlayerHasFullParty
	msgbox HozuniCity_House7_Text_EggLady_CouponFound, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	playfanfare MUS_OBTAIN_ITEM
	removeitem ITEM_EGG_COUPON
	specialvar VAR_RESULT, ChooseRandomEggSpecies
	giveegg VAR_RESULT
	waitfanfare
	fadescreen FADE_FROM_BLACK
	msgbox HozuniCity_House7_Text_EggLady_EggGiven, MSGBOX_AUTOCLOSE
	release
	end

EggLady_Script_PlayerHasFullParty::
	msgbox EggLady_Text_PlayerHasFullParty, MSGBOX_AUTOCLOSE
	release
	end

HozuniCity_House7_EventScript_NoCoupon::
	msgbox HozuniCity_House7_Text_NoCoupon, MSGBOX_AUTOCLOSE
	release
	end

HozuniCity_House7_EventScript_NoEgg::
	msgbox HozuniCity_House7_Text_NoEgg, MSGBOX_AUTOCLOSE
	release
	end

HozuniCity_House7_Text_EggLady_CouponFound:
	.string "Alright! First, I'll take your coupon.\p"
	.string "Now close your eyes and I'll hand you\n"
	.string "a random POKéMON egg.$"

HozuniCity_House7_Text_EggLady_EggGiven:
	.string "Tada! Isn't it so exciting?\n"
	.string "What could be inside?$"

HozuniCity_House7_Text_NoCoupon:
	.string "Ah, it seems like you don't have any Egg\n"
	.string "Coupons to give to me. Come back when\l"
	.string "you find one!$"

HozuniCity_House7_Text_NoEgg:
	.string "If you ever come across an Egg Coupon,\n"
	.string "you can exchange it for one random\l"
	.string "POKéMON egg!$"


HozuniCity_House7_Text_EggLady:
	.string "They call me the Egg Lady.\n"
	.string "Do you have any egg coupons\l"
	.string "to exchange for a random egg?$"

EggLady_Text_PlayerHasFullParty:
	.string "Ah, you're party's full.\p"
	.string "Make room first, then come back.\n"
	.string "Egg's need room to grow, you know.$"
