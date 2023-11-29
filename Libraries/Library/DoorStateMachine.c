
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
		case ST_INIT: // Инициализация параметров 
			{
				inst->state = ST_UNKNOWN;
				break;
			}

		case ST_UNKNOWN: // Ворота в неизвестном положении
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

		case ST_CLOSE: // Ворота закрыты
			{
				inst->speed = 0;
				if(inst->direction == 0)
					inst->state = ST_ACC_POS;
				break;
			}

		case ST_ACC_POS: // Ускорение ворот в сторону открытия
			{
				inst->speed = -200;
				if(inst->sw2 != inst->sw2_last)
					inst->state = ST_POS;
				else if(inst->direction == 1)
					inst->state = ST_DEC_NEG;
				break;	
			}

		case ST_POS: // Движение к открытию
			{
				inst->speed = -400;
				if(inst->sw1 != inst->sw1_last)
					inst->state = ST_DEC_POS;
				else if(inst->direction == 1)
					inst->state = ST_NEG;
				break;	
			}

		case ST_DEC_POS: // Замедление ворот в сторону открытия
			{
				inst->speed = -200;
				if(inst->sw0 != inst->sw0_last)
					inst->state = ST_OPEN;
				else if(inst->direction == 1)
					inst->state = ST_ACC_NEG;
				break;		
			}
		
		case ST_OPEN: // Ворота открыты
			{
				inst->speed = 0;
				if(inst->direction == 1)
					inst->state = ST_ACC_NEG;
				break;		
			}

		case ST_ACC_NEG: // Ускорение ворот в сторону закрытия
			{
				inst->speed = 200;
				if(inst->sw1 != inst->sw1_last)
					inst->state = ST_NEG;
				else if(inst->direction == 0)
					inst->state = ST_DEC_POS;
				break;	
			}

		case ST_NEG: // Движение к закрытию
			{
				inst->speed = 400;
				if(inst->sw2 != inst->sw2_last)
					inst->state = ST_DEC_NEG;
				else if(inst->direction == 0)
					inst->state = ST_POS;
				break;		
			}

		case ST_DEC_NEG: // Замедление ворот в сторону закрытия
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

