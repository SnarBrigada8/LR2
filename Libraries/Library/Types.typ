
TYPE
	DoorStates : 
		(
		ST_INIT,
		ST_UNKNOWN,
		ST_OPEN,
		ST_CLOSE,
		ST_ACC_POS,
		ST_ACC_NEG,
		ST_POS,
		ST_NEG,
		ST_DEC_POS,
		ST_DEC_NEG
		);
	DriveStates : 
		(
		CMD_DISABLE_VOLTAGE := 0,
		CMD_Enable := 15,
		CMD_Shutdown := 6,
		State_Ready := 33,
		State_Disabled := 64,
		CMD_Switch_ON := 7,
		State_Switched_ON := 35
		);
END_TYPE
