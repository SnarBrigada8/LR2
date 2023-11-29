
{REDUND_ERROR} FUNCTION_BLOCK DoorStateMachine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		sw0_last : BOOL;
		sw2_last : BOOL;
		sw3_last : BOOL;
		sw1_last : BOOL;
		sw1 : BOOL;
		sw2 : BOOL;
		sw3 : BOOL;
		sw0 : BOOL;
		direction : BOOL;
		state : DoorStates;
		speed : INT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DriveStateMashine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : {REDUND_UNREPLICABLE} UINT;
		enable : {REDUND_UNREPLICABLE} BOOL;
	END_VAR
	VAR_OUTPUT
		command : {REDUND_UNREPLICABLE} UINT;
		speed : {REDUND_UNREPLICABLE} INT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK LedStateMachine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : {REDUND_UNREPLICABLE} UINT;
	END_VAR
	VAR_OUTPUT
		led1 : {REDUND_UNREPLICABLE} BOOL;
		led2 : {REDUND_UNREPLICABLE} BOOL;
		led3 : {REDUND_UNREPLICABLE} BOOL;
		led4 : {REDUND_UNREPLICABLE} BOOL;
	END_VAR
END_FUNCTION_BLOCK
