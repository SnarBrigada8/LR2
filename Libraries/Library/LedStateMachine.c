
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
void LedStateMachine(struct LedStateMachine* inst)
{
	switch(inst->state)
	{
		case ST_INIT: // Инициализация параметров
			{
				inst->led1 = 0;
				inst->led2 = 0;
				inst->led3 = 0;
				inst->led4 = 0;
				break;
			}

		case ST_UNKNOWN: // Ворота в неизвестном положении
			{
				inst->led1 = !inst->led1;
				inst->led2 = !inst->led2;
				inst->led3 = !inst->led3;
				inst->led4 = !inst->led4;
				break;
			}

		case ST_CLOSE: // Ворота закрыты
			{
				inst->led1 = 1;
				inst->led2 = 1;
				inst->led3 = 1;
				inst->led4 = 1;
				break;
			}

		case ST_ACC_POS: // Ускорение ворот в сторону открытия
			{
				inst->led1 = 1;
				inst->led2 = 1;
				inst->led3 = 1;
				inst->led4 = 0;
				break;	
			}

		case ST_POS: // Движение к открытию
			{
				inst->led1 = 1;
				inst->led2 = 1;
				inst->led3 = 0;
				inst->led4 = 0;
				break;	
			}

		case ST_DEC_POS: // Замедление ворот в сторону открытия
			{
				inst->led1 = 1;
				inst->led2 = 0;
				inst->led3 = 0;
				inst->led4 = 0;
				break;	
			}
		
		case ST_OPEN: // Ворота открыты
			{
				inst->led1 = 0;
				inst->led2 = 0;
				inst->led3 = 0;
				inst->led4 = 0;
				break;	
			}

		case ST_ACC_NEG: // Ускорение ворот в сторону закрытия
			{
				inst->led1 = 1;
				inst->led2 = 0;
				inst->led3 = 0;
				inst->led4 = 0;
				break;	
			}

		case ST_NEG: // Движение к закрытию
			{
				inst->led1 = 1;
				inst->led2 = 1;
				inst->led3 = 0;
				inst->led4 = 0;
				break;	
			}

		case ST_DEC_NEG: // Замедление ворот в сторону закрытия
			{
				inst->led1 = 1;
				inst->led2 = 1;
				inst->led3 = 1;
				inst->led4 = 0;
				break;	
			}
	}
}

