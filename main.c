#include <msp430.h> 
#include <stdio.h>
#include "LCD.h"
#include "Simple-PWM.h"
#include "Serial.h"
#define period 10
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    Serial_Init(); // Initial the serial communication via serial.h

 // Initialize USCI – B1 register to enable I2C communication
    UCB1CTLW0 |= UCSWRST; // Initialize Reset for register with default values
    UCB1CTLW0 |= UCSSEL_3; // Choose the 1MHz clock 
    UCB1BRW = 10; // Set baud rate = 100 KHz)
    UCB1CTLW0 |= UCMODE_3; // Choose communication protocol as I2C mode
// Set Master mode for I2C
    UCB1CTLW0 |= UCMST; //Set B1 as Master mode
    UCB1CTLW0 |= UCTR; //Enable master to Transfer data
    UCB1I2CSA = 0x0027; // Select the receiver(i.e Slave address)
    UCB1CTLW1 |= UCASTP_2; // Enable bit to Automatically stop generation
    UCB1TBCNT = 0x0001; // Move value 0001 to counter
    UCB1CTL1 &= ~UCSWRST; // Disable Reset condition
    UCB1IE |= UCTXIE0; //Set Transmission Interrupts
 // Configure interface for I2C with LED
    P4SEL1 &= ~BIT7; // set SCL   P4.7
    P4SEL0 |= BIT7; 
    P4SEL1 &= ~BIT6; // set SDA  P4.6
    P4SEL0 |= BIT6;
    P4DIR |= BIT0; // Set Pin direction as Output
    LCD_Screen &= ~BIT0;

    P1DIR = 0x0F; // Set port 1 pins 0 to 3 as output and Set port 1 pins P1.4 to P1.7 as Input
    P1REN = 0xFF; // Set port1 as Pull up Register enable
    P1OUT = 0xF0; // Set port1 as Out Register.

    PM5CTL0 &= ~LOCKLPM5; // Remove from High Impedance mode
    __enable_interrupt(); // Enable Interrupt

 // Variable declaration
 unsigned char string[17] = " ";
 unsigned int digits[3] = {0,0,0};
 unsigned int duty = 0;
 unsigned int count=0;
 unsigned int buffer = 0;

     PWM myPWM = Init_PWM(0, period, "P5.1"); // Interface PWM module

// LCD Display Configuration
     LCD_init(0); 
     LCD_Clear(0);
     sprintf(string, "Enter the speed");
     LCD_print_string(string);
     LCD_line(2);
     sprintf(string, "Value...");
     LCD_print_string(string);

 while(1) 
 {

 while((Serial_Received != 1)&&(buffer != END)) // Keeps checking for any signal from the Bluetooth serial module and is high once a value is detected
 {

     count = get_key(); // Fetch the value entered by the user
     if(count != 0) 
     {
 // Store the value in buffer
         buffer = __Key_Val[count];
 // convert numerical value to a digit
if(buffer != END){
    digits[2] = digits[1];
    digits[1] = digits[0];
    digits[0] = buffer;
     }
     }
 }
 // control the speed using keypad
// if((Serial_Received == 1 )&&(Serial_In > 100)) duty = 100;
 //else duty = Serial_In;
 //if(buffer == END){
 //if((duty = digits[2]*100 + digits[1]*10 + digits[0]) >100){
 //    duty = 100;
 }
 }
 // Set Reset condition
     buffer = 0;
     digits[0]=0;
     digits[1]=0;
     digits[2]=0;
 // Display the speed of roation on LCD
     LCD_Clear();
     LCD_line(1);
 // Print duty cycle value from the PWM
     sprintf(string, "%d%%", duty);
     LCD_print_string(string);
 // Set Pulse width modulation
     Adjust_DutyCycle(duty/100.0, myPWM);
     Serial_Received = 0;
     }
 return 0;
}
