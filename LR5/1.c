#include <MDR32F9Qx_port.h>
#include <MDR32F9Qx_rst_clk.h>
#include "lcd.h"

void initPorts(void) {
	RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTB | RST_CLK_PCLK_PORTC | RST_CLK_PCLK_PORTE, ENABLE);

	PORT_InitTypeDef PORT_UpRightButtons;
	PORT_StructInit (&PORT_UpRightButtons);
	PORT_UpRightButtons.PORT_Pin = PORT_Pin_5 | PORT_Pin_6;
	PORT_UpRightButtons.PORT_OE = PORT_OE_IN;
	PORT_UpRightButtons.PORT_FUNC = PORT_FUNC_PORT;
	PORT_UpRightButtons.PORT_MODE = PORT_MODE_DIGITAL;
	PORT_UpRightButtons.PORT_SPEED = PORT_SPEED_SLOW;
	PORT_Init(MDR_PORTB, &PORT_UpRightButtons);
	
	PORT_InitTypeDef PORT_SelectButton;
	PORT_StructInit (&PORT_SelectButton);
	PORT_SelectButton.PORT_Pin = PORT_Pin_1;
	PORT_SelectButton.PORT_OE = PORT_OE_IN;
	PORT_SelectButton.PORT_FUNC = PORT_FUNC_PORT;
	PORT_SelectButton.PORT_MODE = PORT_MODE_DIGITAL;
	PORT_SelectButton.PORT_SPEED = PORT_SPEED_SLOW;
	PORT_Init(MDR_PORTC, &PORT_SelectButton);
	
	PORT_InitTypeDef PORT_LeftDownButtons;
	PORT_StructInit (&PORT_LeftDownButtons);
	PORT_LeftDownButtons.PORT_Pin = PORT_Pin_1 | PORT_Pin_3;
	PORT_LeftDownButtons.PORT_OE = PORT_OE_IN;
	PORT_LeftDownButtons.PORT_FUNC = PORT_FUNC_PORT;
	PORT_LeftDownButtons.PORT_MODE = PORT_MODE_DIGITAL;
	PORT_LeftDownButtons.PORT_SPEED = PORT_SPEED_SLOW;
	PORT_Init(MDR_PORTE, &PORT_LeftDownButtons);
}

int main()
{
	initPorts();
	LCD_Init();
	uint8_t x = 0;
	uint8_t y = 0;
	uint8_t s = ' ';
	int selectMode = 0;
	while (1)
	{
		if (selectMode) {
			LCD_PutSymbol('x', x, y);
		}
		else {
			LCD_PutSymbol('+', x, y);
		}
		
		if(!(PORT_ReadInputDataBit(MDR_PORTC,PORT_Pin_2))){ //if SELECT pressed
			selectMode++;
			selectMode = selectMode % 2;
			if (selectMode) {
				s = '.';
			}
			else {
				s = ' ';
			}
		}
				
		if(!(PORT_ReadInputDataBit(MDR_PORTE,PORT_Pin_3))){ //if LEFT pressed
			LCD_PutSymbol(s, x, y);
			if(x == 0) {
				x = 15;
			}
			else {
				x--;
			}
		}
		if(!(PORT_ReadInputDataBit(MDR_PORTE,PORT_Pin_1))){ //if DOWN pressed
			LCD_PutSymbol(s, x, y);
			if(y == 7) {
				y = 0;
			}
			else {
				y++;
			}
		}
		if(!(PORT_ReadInputDataBit(MDR_PORTB,PORT_Pin_6))){ //if RIGHT pressed
			LCD_PutSymbol(s, x, y);
			if(x == 15) {
				x = 0;
			}
			else {
				x++;
			}
		}
		if(!(PORT_ReadInputDataBit(MDR_PORTB,PORT_Pin_5))){ //if UP pressed
			LCD_PutSymbol(s, x, y);
			if(y == 0) {
				y = 7;
			}
			else {
				y--;
			}
		}
	}
}
