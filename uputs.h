void Uputs( char *a){

    //while(!(IFG2&UCA0TXIFG));
    while(*a)
         {

         UCA0TXBUF =*a;

 __delay_cycles(1200);
     *a++;

        }

     }
