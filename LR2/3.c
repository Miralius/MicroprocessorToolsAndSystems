//part of the code

#pragma vector=TIMERA0_VECTOR
__interrupt void TimerA0_ISR (void)
{	
 if (mode)
 {
   msec++;				        // manage memory clock
 LCD_msec();

 if (msec == 10)
  {
  	msec = 0;
  	sec++;
  	LCD_sec();
  	if (sec == 60)
  	{
  		sec = 0;
  		min++;
  		LCD_min();
  		if (min == 60)
  		{
  			min = 0;
  		}
  	}
  }	

 if (sec & 0x01)			    // toogle clock dots
    {
      P3_DOT_ON;	
      P5_DOT_ON;
    }
 else
    {
      P3_DOT_OFF;
      P5_DOT_OFF;
    }
 }
}
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{	
  if (P1IFG == 0x01)                        // SW1 interrupt
  {
        mode = 1;
  }

  if (P1IFG == 0x02)                        // SW2 interrupt
  {
   	mode = 0;
  }

  P1IFG = 0x00;	                             // clean all pending interrupts
}
