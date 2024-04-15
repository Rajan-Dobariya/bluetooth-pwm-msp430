#include <msp430.h>
#include "LCD.h"

unsigned val=0x00;

void LCD_Clear()
{
    _4Bit_Send(0x01, 0x08);
}

// Prints a string (can only be 16 characters long)
void LCD_print_string(unsigned char str[]){
    int j = 0;

    while(str[j] != '\0'){
        _4Bit_Send(str[j],0x09);
        j++;
    }
 }

// Sets cursor to home
void LCD_line(int n){
    int i = 0;
    // Set cursor to line 1
    if( n == 1) _4Bit_Send(0x02, 0x08);

    // Set Cursor to line 2
    else if(n == 2)
    {
        _4Bit_Send(0x02, 0x08);
        for(i = 0; i<40; i++){
            // Shift Cursor Right
            _4Bit_Send(0x14, 0x08);
            }
    }
 }

// Initializes LCD and blinks
void LCD_init(int cursor)
    {
    // Power Cycle the LCD for reliability
        LCD_Screen  &= ~BIT0;
        __delay_cycles(15000);
        LCD_Screen |= BIT0;
        __delay_cycles(15000);

    // Set communication to 4 bit mode
       _send(0x28);

   // Keep in 4 bit mode and send 5x8  Configure LCD (2 lines, 8x5 LCD Char)
       // Sending 0x28
       _send(0x28);
       _send(0x88);

   // Clear Display
       // Using 4 bit function
       _4Bit_Send(0x01, 0x08);

   // Blink Cursors
       if(cursor == 1) _4Bit_Send(0x0F , 0x08);
   // No Cursor
       else if (cursor == 0) _4Bit_Send(0b00001100, 0x08);
   // Set Cursor at Home
       _4Bit_Send(0x02, 0x08);

    }

// D7 D6 D5 D4 BL EN RW RS
void _send(unsigned char x){
    // Send value
        int i = 0;
        val=x;
        UCB1CTLW0 |= UCTXSTT;
        for(i = 0;i<100;i++){}
        __delay_cycles(__delay_time);

    // Set Enable
        val |= 0X04;
        UCB1CTLW0 |= UCTXSTT;
        for(i = 0;i<100;i++){}
        __delay_cycles(__delay_time);

    // Clear Enable
        val &= ~0X04;
        UCB1CTLW0 |= UCTXSTT;
        for(i = 0;i<100;i++){}
        __delay_cycles(__delay_time);
        }

// command: D7-D0, cmd_signals: BL EN R/W RS
void _4Bit_Send(unsigned command, unsigned cmd_signals) {
    // Setting up variables
        unsigned char tmp1 = 0x00;
        unsigned char tmp2 = 0x00;

        tmp1 = ((command<<4)&(0xF0)) | (0x0F & cmd_signals);
        tmp2 = ((command) & 0xF0)    | (0x0F & cmd_signals);

    // Send first and second nibbles
        _send(tmp2);
        _send(tmp1);
    }

// I2C interrupt vector eUSCIB1
#pragma vector = EUSCI_B1_VECTOR
    __interrupt void EUSCIB1_I2C_ISR(void)
    {
        UCB1TXBUF= val;
    }
