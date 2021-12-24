//part of the code

#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{	
  if (P1IFG == 0x01)                        // SW1 interrupt
  {
       mode++;
       mode=mode%2;
       if (mode)
       {
         ENV_ON;
       }
       else
       {
         ENV_OFF;
       }
  }

  P1IFG = 0x00;	                             // clean all pending interrupts
}