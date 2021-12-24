#include <MDR32F9Qx_port.h>
#include <MDR32F9Qx_rst_clk.h>
#define DELAY(T) for (i = T; i > 0; i--)
int i;

void SetClock(int F)
{
	RST_CLK_HSEconfig (RST_CLK_HSE_ON);
	while (RST_CLK_HSEstatus () != SUCCESS);
	uint32_t RST_CLK_CPU_PLLsrcHSEdivValue;
	uint32_t RST_CLK_CPU_PLLmulValue;
	switch (F) {
		case 1: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul1;
		break;
		case 2: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV4; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul1;
		break;
		case 3: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul3;
		break;
		case 4: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV2; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul1;
		break;
		case 5: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul5;
		break;
		case 6: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul6;
		break;
		case 7: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul7;
		break;
		case 8: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul1;
		break;
		case 9: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul9;
		break;
		case 10: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul10;
		break;
		case 11: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul11;
		break;
		case 12: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul12;
		break;
		case 13: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul13;
		break;
		case 14: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul14;
		break;
		case 15: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV8; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul15;
		break;
		case 16: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul2;
		break;
		case 18: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV4; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul9;
		break;
		case 20: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV2; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul5;
		break;
		case 22: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV4; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul11;
		break;
		case 24: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul3;
		break;
		case 26: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV4; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul13;
		break;
		case 28: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV4; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul14;
		break;
		case 30: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV4; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul15;
		break;
		case 32: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul4;
		break;
		case 36: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV2; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul9;
		break;
		case 40: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul5;
		break;
		case 44: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV2; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul11;
		break;
		case 48: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul6;
		break;
		case 52: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV2; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul13;
		break;
		case 56: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul7;
		break;
		case 60: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV2; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul15;
		break;
		case 64: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul8;
		break;
		case 72: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul9;
		break;
		case 80: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul10;
		break;
		case 88: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul11;
		break;
		case 96: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul12;
		break;
		case 104: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul13;
		break;
		case 112: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul14;
		break;
		case 120: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul15;
		break;
		case 128: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul16;
		break;
		default: RST_CLK_CPU_PLLsrcHSEdivValue = RST_CLK_CPUclkDIV1; RST_CLK_CPU_PLLmulValue = RST_CLK_CPU_PLLmul1;
	}
	RST_CLK_CPU_PLLconfig (RST_CLK_CPU_PLLsrcHSEdiv1, RST_CLK_CPU_PLLmulValue);
	RST_CLK_CPU_PLLcmd (ENABLE);
	while (RST_CLK_CPU_PLLstatus () != SUCCESS);
	RST_CLK_CPUclkPrescaler (RST_CLK_CPU_PLLsrcHSEdivValue);
	RST_CLK_CPU_PLLuse (ENABLE);
	RST_CLK_CPUclkSelection (RST_CLK_CPUclkCPU_C3);
}

int main()
{
	int F = 40;
	SetClock(F);
	RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTC, ENABLE);
	PORT_InitTypeDef Nastroyka;
	Nastroyka.PORT_Pin = PORT_Pin_0;
	Nastroyka.PORT_OE = PORT_OE_OUT;
	Nastroyka.PORT_FUNC = PORT_FUNC_PORT;
	Nastroyka.PORT_MODE = PORT_MODE_DIGITAL;
	Nastroyka.PORT_SPEED = PORT_SPEED_SLOW;
	PORT_Init (MDR_PORTC, &Nastroyka);
	while (1)
	{
	PORT_SetBits(MDR_PORTC, PORT_Pin_0);
	DELAY(100000);
	PORT_ResetBits(MDR_PORTC, PORT_Pin_0);
	DELAY(100000);
	}
}
