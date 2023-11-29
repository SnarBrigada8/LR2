
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
void DoorStateMachine(struct DoorStateMachine* inst)
{
	switch(inst->state)
	{
		case ST_INIT: // ������������� ���������� 
			{
				inst->state = ST_UNKNOWN;
				break;
			}

		case ST_UNKNOWN: // ������ � ����������� ���������
			{
				if(inst->direction == 1)
				{
					inst->speed = 100;
					if(inst->sw3 != inst->sw3_last)
						inst->state = ST_CLOSE;
				}

				if(inst->direction == 0)
				{
					inst->speed = -100;
					if(inst->sw0 != inst->sw0_last)
						inst->state = ST_OPEN;
				}

				break;
			}

		case ST_CLOSE: // ������ �������
			{
				inst->speed = 0;
				if(inst->direction == 0)
					inst->state = ST_ACC_POS;
				break;
			}

		case ST_ACC_POS: // ��������� ����� � ������� ��������
			{
				inst->speed = -200;
				if(inst->sw2 != inst->sw2_last)
					inst->state = ST_POS;
				else if(inst->direction == 1)
					inst->state = ST_DEC_NEG;
				break;	
			}

		case ST_POS: // �������� � ��������
			{
				inst->speed = -400;
				if(inst->sw1 != inst->sw1_last)
					inst->state = ST_DEC_POS;
				else if(inst->direction == 1)
					inst->state = ST_NEG;
				break;	
			}

		case ST_DEC_POS: // ���������� ����� � ������� ��������
			{
				inst->speed = -200;
				if(inst->sw0 != inst->sw0_last)
					inst->state = ST_OPEN;
				else if(inst->direction == 1)
					inst->state = ST_ACC_NEG;
				break;		
			}
		
		case ST_OPEN: // ������ �������
			{
				inst->speed = 0;
				if(inst->direction == 1)
					inst->state = ST_ACC_NEG;
				break;		
			}

		case ST_ACC_NEG: // ��������� ����� � ������� ��������
			{
				inst->speed = 200;
				if(inst->sw1 != inst->sw1_last)
					inst->state = ST_NEG;
				else if(inst->direction == 0)
					inst->state = ST_DEC_POS;
				break;	
			}

		case ST_NEG: // �������� � ��������
			{
				inst->speed = 400;
				if(inst->sw2 != inst->sw2_last)
					inst->state = ST_DEC_NEG;
				else if(inst->direction == 0)
					inst->state = ST_POS;
				break;		
			}

		case ST_DEC_NEG: // ���������� ����� � ������� ��������
			{
				inst->speed = 200;
				if(inst->sw3 != inst->sw3_last)
					inst->state = ST_CLOSE;
				else if(inst->direction == 0)
					inst->state = ST_ACC_POS;
				break;		
			}
	}
	inst->sw0_last = inst->sw0;
	inst->sw1_last = inst->sw1;
	inst->sw2_last = inst->sw2;
	inst->sw3_last = inst->sw3;
}

