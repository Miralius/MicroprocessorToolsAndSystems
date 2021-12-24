//part of the code

#pragma vector=TIMERA0_VECTOR
__interrupt void TimerA0_ISR (void)
{	
 msec++;

 if (msec == 5)
  {
  	msec = 0;
        mode++;
        mode=mode%2;
        if (mode)
        {
          ANT_ON;
        }
        else
        {
          ANT_OFF;
        }
  }	
}

#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{	
  if (P1IFG == 0x01)                        // SW1 interrupt
  {
        RX_ON;
        TX_OFF;
  }

  if (P1IFG == 0x02)                        // SW2 interrupt
  {
   	TX_ON;
        RX_OFF;
  }

  P1IFG = 0x00;	                             // clean all pending interrupts
}
