void initUART()
{

    UCA0CTL1 |= UCSSEL_2;                     // SMCLK
    UCA0BR0 = 8;                            // 16MHz 115200
    UCA0BR1 = 0;                              // 16MHz 115200
    UCA0MCTL = UCBRS2+UCBRS0;                       // Modulation UCBRSx = 7
    UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    IFG2 &= ~(UCA0RXIFG);
    IE2 |= UCA0RXIE ;               // Enable USCI_A0 TX/RX interrupt

}
void initClockTo16MHz()
{

    DCOCTL = 0;                              // Select lowest DCOx and MODx settings
    BCSCTL1 = CALBC1_1MHZ;                  // Set DCO
    DCOCTL = CALDCO_1MHZ;
}

void initGPIO()
{
    P1SEL = BIT1 + BIT2;                      // P1.1 = RXD, P1.2=TXD
    P1SEL2 = BIT1 + BIT2;
    P1OUT=0;
}
