#include <MDR32F9Qx_port.h>
#include <MDR32F9Qx_rst_clk.h>
#define DELAY(T) for (i = T; i > 0; i--)
int i;

void CPU_init ( void ){
     //Необходимая пауза для работы Flash-памяти программ
     MDR_EEPROM->CMD |= (3 << 3);

     MDR_RST_CLK->HS_CONTROL = 0x01;// вкл. HSE осцилятора (частота кварца 8 МГц)
     while ((MDR_RST_CLK->CLOCK_STATUS & (1 << 2)) == 0x00);// ждем пока HSE выйдет в рабочий режим

     MDR_RST_CLK->CPU_CLOCK = ((2 << 0));//подача частоты на блок PLL
     MDR_RST_CLK->PLL_CONTROL = ((1 << 2) | (9 << 8));//вкл. PLL  | коэф. умножения = 10
     while ((MDR_RST_CLK->CLOCK_STATUS & 0x02) != 0x02);// ждем когда PLL выйдет в раб. режим

     MDR_RST_CLK->CPU_CLOCK = ((2 << 0)//источник для CPU_C1
                             | (1 << 2)//источник для CPU_C2
                             | (0 << 4)//предделитель для CPU_C3
                             | (1 << 8));//источник для HCLK

     MDR_BKP->REG_0E |= (7 << 0); //режим встроенного регулятора напряжения DUcc
     MDR_BKP->REG_0E |= (7 << 3); //выбор доп.стабилизирующей нагрузки
}//void CPU_init

int main()
{
	CPU_init();
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
