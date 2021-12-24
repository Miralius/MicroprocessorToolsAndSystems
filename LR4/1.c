#include <MDR32F9Qx_port.h>
#include <MDR32F9Qx_rst_clk.h>
#define DELAY(T) for (i = T; i > 0; i--)
int i;

void initPorts(void) {
	RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTC | RST_CLK_PCLK_PORTE, ENABLE);
	
	PORT_InitTypeDef PORT_Diod;
	PORT_StructInit (&PORT_Diod);
	PORT_Diod.PORT_Pin = PORT_Pin_0;
	PORT_Diod.PORT_OE = PORT_OE_OUT;
	PORT_Diod.PORT_FUNC = PORT_FUNC_PORT;
	PORT_Diod.PORT_MODE = PORT_MODE_DIGITAL;
	PORT_Diod.PORT_SPEED = PORT_SPEED_SLOW;
	PORT_Init(MDR_PORTC, &PORT_Diod);
	
	PORT_InitTypeDef PORT_LeftButton;
	PORT_StructInit (&PORT_LeftButton);
	PORT_LeftButton.PORT_Pin = PORT_Pin_3;
	PORT_LeftButton.PORT_OE = PORT_OE_IN;
	PORT_LeftButton.PORT_FUNC = PORT_FUNC_PORT;
	PORT_LeftButton.PORT_MODE = PORT_MODE_DIGITAL;
	PORT_LeftButton.PORT_SPEED = PORT_SPEED_SLOW;
	PORT_Init(MDR_PORTE, &PORT_LeftButton);
}

int main()
{
	initPorts();
	while (1)
	{
		if(PORT_ReadInputDataBit(MDR_PORTE,PORT_Pin_3)) {
			PORT_SetBits(MDR_PORTC, PORT_Pin_0);
		}
		else {
			PORT_ResetBits(MDR_PORTC, PORT_Pin_0);
		}
	}
}
