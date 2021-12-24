//part of the code

void show_pi(void)
{
  switch (count)
  {
  case 0:
    P7_A0;
    P6_DOT_OFF;
    P6_A0;
    P5_A0;
    P4_A0;
    P3_A0;
    P2_A0;
    P1_A0;
  break;
  case 1:
    P7_A3;
    P6_A1;
    P6_DOT_ON;
    P5_A4;
    P4_A1;
    P3_A5;
    P2_A9;
    P1_A2;
  }
}

#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{	
  if (P1IFG == 0x01
  {
        count++;
        count=count%2;
        show_pi();
  }

  P1IFG = 0x00;
}
