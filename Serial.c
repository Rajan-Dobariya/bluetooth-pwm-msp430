#include "Serial.h"


//Received Data
// Variables to be used in main.c and Serial.c
unsigned Serial_In = 0x00;
unsigned Serial_Received = 0x00;

// Configure UART
void Serial_Init(){

    UCA1CTLW0 |= UCSWRST;                     // Put eUSCI in reset
    UCA1CTLW0 |= UCSSEL__ACLK;               // Select 1MHz clock

    // Baud Rate calculation
    UCA1BR0 = 3;                              // 1000000/115200 = 8.68
    UCA1MCTLW = 0x9200;                       // 1000000/115200 - INT(1000000/115200)=0.68
                                           // UCBRSx value = 0xD6 (See UG)
    // Configure UART pins
    P4SEL1 &= ~BIT2;                       // Select P4.2 for serial communication
    P4SEL0 |= BIT2;

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    UCA1CTLW0 &= ~UCSWRST;                    // Initialize eUSCI
    UCA1IE |= UCRXIE;
}

// Interrupt Vector for when data is received
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
    // Received Data
    Serial_In = UCA1RXBUF;
    Serial_Received = 1;
}
