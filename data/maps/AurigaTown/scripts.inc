AurigaTown_MapScripts::
	.byte 0

AurigaTown_EventScript_CitySign::
	msgbox AurigaTown_Text_CitySign, MSGBOX_DEFAULT
	release
	end

AurigaTown_Text_CitySign:
	.string "AURIGA TOWN\n"
	.string "“The town nestled beneath the\l"
	.string "mountains.”$"