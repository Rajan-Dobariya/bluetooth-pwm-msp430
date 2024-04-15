# bluetooth-pwm-msp430

Title: **Bluetooth-Controlled PWM Motor**

Objective:

To control the speed of a motor depending on the Pulse Width Modulation (PWM) via a wireless medium (Bluetooth control). Have a DC motor whose speed and direction of rotation can be controlled through the **MSP-EXP430FR2355** microcontroller.. Clock speed is controlled by PWM to generate the required speed for the motor. The input for the speed of the motor is decided by the user and is generated via Bluetooth control (Mobile Phones). Further, the speed of the motor is displayed on the LCD screen for verification.


## Pseudocode for bluetooth-pwm-msp430

### Steps:

**Step 1**: An LCD interface of 2x16 is used to display the messages for the User. The LCD module comes with the I2C interface and hence eUSCI registers with B1 register is used to interface the LCD module.\
**Step 2**: The 1MHz clock is used to define the pulse width modulation and can be used to control the speed of the motor based on the desired duty cycle.\
**Step 3**: Define the serial Bluetooth communication for defining the speed of the motor. Here, ascii values of the character are used as a reference value for speed. A = 65% speed , a = 97% of speed and so on.\
**Step 4**: Interface all the modules to the main assembly code and define the interdependency of the modules with one another.



## Description:

The system is used to control the speed of rotation of a 12V DC motor. The motor speed can be decided via pulse width modulation to increase or decrease the duty cycle. A Bluetooth module is used to enable wireless communication in addition to I2C communication. A mobile phone is used as a Bluetooth transmitter which can send characters and its equivalent ASCII value is considered to be the speed of rotation. Hence, we can choose the character until ‘d’ which gives 100% rotation speed (ASCII value of d is 100). Similarly, the different character chosen gives different speed for the motor. An LCD screen is used to display the status of the system. It displays the exact percentage of the rotation speed of the motor in numerical value. The LCD screen has an I2C communication module that facilitates communication between the microcontroller and the LCD, and any message can be displayed using this module.


## Output

[Video link](https://usfedu-my.sharepoint.com/:v:/g/personal/dobariya_usf_edu/EVHSdbyUw3RKmdeLF25cI4gBVhc622EzPDILCgI8rgulWA?e=lp9uxr)