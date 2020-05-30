#include <msp430.h> 
#include<Uputs.h>
#include<Uartinit.h>
#include<lcd.h>
#include <stdint.h>
#include<crc16.h>
#include <stdbool.h>
char check[50];
int control_char;
int counter=0;
char *findch=',';
char *stringIn;
char carry[50];
volatile uint8_t emre[100];
volatile uint8_t rx;
volatile uint8_t rev[20];
volatile uint8_t son[20];
volatile int say=0;
volatile int say1=0;
volatile int say2=0;
volatile int say3=0;
volatile char huso[20];
volatile char crcarr[20];
int boy;
int boy2;
char basinc;

/////////////////////////////////print///////////////////////////////////
volatile uint8_t temp[20];
volatile uint8_t air[20];
////////////////////////////////////////////////////////////////////////
/**
 * main.c
 */



int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //while(crcarr[0]!='h'&& crcarr[1]!='i'){
    initClockTo16MHz(); //set clock
    //lcd///
    BCSCTL3= LFXT1S_2;          /* Mode 2 for LFXT1 : VLO */
    P2DIR = 0x07;               /* PORT2, PIN 0-1-2 ENABLED */
    P2SEL = 0x00;               /* PORT2 BECAME GPIO(GENERAL PURPOSE I/O) */
    P1OUT |= BIT6;
     P1REN |= BIT6;
     P1OUT |= BIT5;
         P1REN |= BIT5;
    __delay_cycles(2000);       /* DELAY */
    ////////////////////////////////
    initialize();
            gotoxy(1,1);
            write("");
            gotoxy(2,1);
            write("  ");
            gotoxy(4,1);
            write("");

   while((P1IN & BIT6)!=BIT6);
    initialize();
        gotoxy(1,1);
        write("");
        gotoxy(2,1);
        write("PRESS BUTTON");
        gotoxy(4,1);
        write("TO START");

      while((P1IN & BIT5)!=BIT5);
        initialize();
        gotoxy(1,1);
        write("");
        gotoxy(2,1);
        write("");
        gotoxy(4,1);
        write("");

        initialize();
                gotoxy(1,1);
                write("");
                gotoxy(2,1);
                write("   LIVE LONG   ");
                gotoxy(4,1);
                write("  AND PROSPER!  ");
    initGPIO();//sel ayarý
    initUART();//configrasyon
    _BIS_SR(GIE);//enable rx interrupt

/*******built at*******/
    Uputs((char*)"AT+CWMODE=3\r\n");
       __delay_cycles(50000);
       counter=0;
     Uputs((char*)"ATE0\r\n");
        __delay_cycles(50000);
        counter=0;
        Uputs((char*)"AT+CWMODE=3\r\n");
           __delay_cycles(50000);
           counter=0;
           Uputs((char*)"AT+CWJAP=\"ELE417\",\"EmbeddeD\"\r\n");
       __delay_cycles(10000000);
       counter=0;
       Uputs((char*)"AT+CIPSTART=\"TCP\",\"10.50.106.10\",10000\r\n");
    __delay_cycles(5000000);
    clear(emre);
    Uputs((char*)"AT+CIPSEND=2\r\nhi\r\n");
    __delay_cycles(5000000);
/****************/

while(1){

///lcd temiz///

///////////////////////////////////////////////////
clear(emre);
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Temperature
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");

///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Temperature (C)");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);

//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Air Pressure(hpa)
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Air Pressure|mmHg");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Humidity(%)
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Humidity(%)");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Wind Speed(m/s)
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Wind Speed(m/s)");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Cloudiness(%)
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Cloudiness(%)");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Weather Status
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Weather Status");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Current Time
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Current Time");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Current Date
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Current Date");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\t\r\n");//Uptime
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("Uptime");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
//////////////////////
Uputs((char*)"AT+CIPSEND=2\r\nî\r\n");//Connected # of Clients
__delay_cycles(700000);
ayik(emre);
__delay_cycles(300000);
yaz(rev);
__delay_cycles(300000);
yaz2(rev);
__delay_cycles(300000);
///lcd temiz///
    initialize();
    gotoxy(1,1);
    write("");
    gotoxy(2,1);
    write("");
    gotoxy(4,1);
    write("");
///////////////////////////////////////////////////
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("# of Connections");
gotoxy(4,1);
write(crcarr);
__delay_cycles(700000);
///arry clear///
clear(emre);
clear(rev);
clear(crcarr);
initialize();
gotoxy(1,1);
write("");
gotoxy(2,1);
write("");
gotoxy(4,1);
write("");
}




    return 0;
}

//**********
// UART RX Interrupt *******
//**********

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
    if (IFG2 & UCA0RXIFG)
    {
        rx  = UCA0RXBUF;        //Must read UCxxRXBUF to clear the flag


            sendData(&rx);
    }

}

//void SendUCA0Data(rx_val){
//
//        check[counter]=rx_val;
//
//        counter++;
//
//
//}


void yaz2(char *koray){
boy= rev[1] ;
boy2=boy-4;
  /* crcarr[0]=koray[boy-2];
   crcarr[1]=koray[boy-1];*/ //deðiþtirdik
int abc;
for(abc=0;abc<boy2;abc++){
    crcarr[abc]=rev[abc+2];

}

}


//////////////////////////////////////////////////
void yaz(char *koray){
int boy= rev[2] ;
    volatile int abla=2;
    volatile int p=0;
    while(p<(boy-2)){
        son[p]=koray[abla];
        p++;
        abla++;
    }

}
void ayik(char *alper){
    while(say1<254){
    if(alper[say1]>0 && alper[say1]<10){
        while(alper[say1]){
            rev[say2]=alper[say1];
            say1++;
            say2++;
        }

    }
    else if(alper[say1]==11){
        while(alper[say1]){
                    rev[say2]=alper[say1];
                    say1++;
                    say2++;
    }}
    else
        say1++;
    }
}

void sendData(char *rx){
    emre[say]=*rx;

    say++;

}

int clear(char *temiz){
    int b=254;
    while (b>=0){
        temiz[b]= '\0';
        b--;
    }
    say=0;
    say1=0;
    say2=0;

}
