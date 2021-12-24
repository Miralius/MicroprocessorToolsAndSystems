//part of the code

void running_line(void)
{
  switch (mode)
  {
    case 1: P7_NULL; P6_NULL; P5_NULL; P4_NULL; P3_NULL; P2_NULL; P1_A0; break;
    case 2: P7_NULL; P6_NULL; P5_NULL; P4_NULL; P3_NULL; P2_A0; P1_A0; break;
    case 3: P7_NULL; P6_NULL; P5_NULL; P4_NULL; P3_A0; P2_A0; P1_A6; break;
    case 4: P7_NULL; P6_NULL; P5_NULL; P4_A0; P3_A0; P2_A6; P1_A6; break;
    case 5: P7_NULL; P6_NULL; P5_A0; P4_A0; P3_A6; P2_A6; P1_A6; break;
    case 6: P7_NULL; P6_A0; P5_A0; P4_A6; P3_A6; P2_A6; P1_NULL; break;
    case 7: P7_A0; P6_A0; P5_A6; P4_A6; P3_A6; P2_NULL; P1_NULL; break;
    case 8: P7_A0; P6_A6; P5_A6; P4_A6; P3_NULL; P2_NULL; P1_NULL; break;
    case 9: P7_A6; P6_A6; P5_A6; P4_NULL; P3_NULL; P2_NULL; P1_NULL; break;
    case 10:P7_A6; P6_A6; P5_NULL; P4_NULL; P3_NULL; P2_NULL; P1_NULL; break;
    case 11:P7_A6; P6_NULL; P5_NULL; P4_NULL; P3_NULL; P2_NULL; P1_NULL; break;
    case 12:P7_NULL; P6_NULL; P5_NULL; P4_NULL; P3_NULL; P2_NULL; P1_NULL; break;
  }
}
#pragma vector=TIMERA0_VECTOR
__interrupt void TimerA0_ISR (void)
{	
 msec++;
 mode=msec%13;
 running_line();
}
