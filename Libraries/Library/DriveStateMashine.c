
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DriveStateMashine(struct DriveStateMashine* inst)
{
	UINT mask = inst->state&0x6f;
	if(!inst->enable)
	{
		inst->command = CMD_Shutdown; // Выключить двигатель
	}
	else
	{	
		switch(mask)
		{
			case State_Disabled: // Система выключена			
				inst->command = CMD_Shutdown; // Выключить двигатель
				break;
			
			case State_Ready: // Система готова к работе
				inst->command = CMD_Enable; // Приготовиться к работе
				break;
			
			case State_Switched_ON: // Система работает
				inst->command = CMD_Switch_ON; // Включить двигатель
				break;
		}
	}	
}
