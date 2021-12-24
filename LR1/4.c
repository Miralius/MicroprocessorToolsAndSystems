#include "msp430x14x.h"
#define Num_of_Results 200
unsigned int indexFirst = 0;
unsigned int indexSecond = 0;
unsigned int resultsFirst[Num_of_Results],resultsSecond[Num_of_Results];
void main(void)
{
WDTCTL = WDTPW+WDTHOLD;
ADC12CTL0 = ADC12ON+REFON+REF2_5V+SHT0_6;
ADC12CTL1 = SHP+CONSEQ1;
ADC12MCTL0 = INCH_10+SREF_1;
ADC12MCTL1 = INCH_11+SREF_1+EOS;
ADC12IE = 0x01; 
for (int i=0; i<0x3600; i++) { }
ADC12CTL0 |= ENC; 
_EINT();
while(1)
{
ADC12CTL0 |= ADC12SC; 
_BIS_SR(LPM0_bits);
_NOP();
}
}
#pragma vector=ADC_VECTOR
__interrupt void ADC12_ISR ()
{
if (ADC12IV == ADC12IV_ADC12IFG0) {
    resultsFirst[indexFirst] = ADC12MEM0;
    indexFirst = (indexFirst+1)%Num_of_Results;
  }
  if (ADC12IV == ADC12IV_ADC12IFG1) {
    resultsSecond[indexSecond] = ADC12MEM1;
indexSecond = (indexSecond+1)%Num_of_Results;
  }
_BIC_SR_IRQ(LPM0_bits);
}
