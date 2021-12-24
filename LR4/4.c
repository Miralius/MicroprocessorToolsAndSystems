#include <MDR32F9Qx_port.h>
#include <MDR32F9Qx_rst_clk.h>
#define DELAY(T) for (i = T; i > 0; i--)
int i;

void SetClock(void)
{
RST_CLK_CPUclkSelection (RST_CLK_CPUclkLSI);
}

int main()
{
	SetClock();
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
