
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	doorSM.state = ST_INIT;
	DoorStateMachine(&doorSM);
	driveSM.enable = 1;
	DriveStateMashine(&driveSM);	
}
