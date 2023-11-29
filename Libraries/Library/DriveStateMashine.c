
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
		inst->command = CMD_Shutdown; // ��������� ���������
	}
	else
	{	
		switch(mask)
		{
			case State_Disabled: // ������� ���������			
				inst->command = CMD_Shutdown; // ��������� ���������
				break;
			
			case State_Ready: // ������� ������ � ������
				inst->command = CMD_Enable; // ������������� � ������
				break;
			
			case State_Switched_ON: // ������� ��������
				inst->command = CMD_Switch_ON; // �������� ���������
				break;
		}
	}	
}
