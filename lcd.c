#include <msp430.h>
#include "lcd.h"

void three_wire_control(unsigned char temp)
{
char i;
for(i=0;i<8;i++)
{
if(temp&0x80)
LCD_PORT |= DATAIO_PIN;
else
LCD_PORT&=~ DATAIO_PIN;
LCD_PORT|= CLOCK_PIN;
LCD_PORT&=~ CLOCK_PIN;
temp*=2;;
}
LCD_PORT|= ENABLE_PIN;
LCD_PORT&=~ ENABLE_PIN;
}
void lcd_busy(void)
{
__delay_cycles(2000);
}
void command(unsigned char c)
{
unsigned char temp;
temp = 0x00;
temp |= 0x04;
three_wire_control(temp);
temp |= ( c & 0xF0 );
three_wire_control(temp);
temp &= 0xF0;
three_wire_control(temp);
lcd_busy();
temp = 0x00;
temp |= 0x04;
three_wire_control(temp);
temp |= ( (c & 0x0F)<<4 );
three_wire_control(temp);
temp &= 0xF0;
three_wire_control(temp);
lcd_busy();
}
void send_data(unsigned char c)
{
unsigned char temp=0;
temp |= 0x05;
three_wire_control(temp);
temp |= ( c & 0xF0 );
three_wire_control(temp);
temp &= 0xF1;
three_wire_control(temp);
lcd_busy();
temp = 0x00;
temp |= 0x05;
three_wire_control(temp);
temp |= ( (c & 0x0F)<<4 );
three_wire_control(temp);
temp &= 0xF1;
three_wire_control(temp);
lcd_busy();
}
void clearlcd(void)
{
command(0x1);
__delay_cycles(2000);
}
void write(const char *s)
{
lcd_busy();
while(*s)
send_data(*s++);
}
void gotoxy(unsigned char x,unsigned char y)
{
if(x==2)
command(0x80+((y-1)%20));
else
command(0xC0+((y-1)%20));
}
void enable(void)
{
three_wire_control(0x04);_NOP();_NOP();_NOP();_NOP();three_wire_control(0x00);
}
void initialize()
{
three_wire_control(0);
__delay_cycles(2000);
command(0x03);
__delay_cycles(2000);
enable();
__delay_cycles(2000);
enable();
command(0x02);
__delay_cycles(2000);
command(TWOROW4BIT);
command(WRITERIGHT);
command(HIDE);
clearlcd();
command(FIRSTROW);
}
