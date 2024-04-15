#include "Simple-PWM.h"
#include <msp430.h>

extern volatile unsigned int __absolute_trash__;

PWM __null_PWM_struct__();

struct PWM_PIN Init_PWM(float Duty_Cycle, float period, char PIN[4]){

    unsigned int actual_Period = (unsigned int)(32.768*period);
    if(actual_Period < 4) actual_Period = 4;

    unsigned int actual_PWM = (unsigned int)((Duty_Cycle)*actual_Period);
    if(actual_PWM > actual_Period) actual_PWM = actual_Period;

    struct PWM_PIN tmp;
    switch(*(PIN+1))
    {
        case '1':
            switch(*(PIN+3)){
                case '6':
                    
                    P1DIR |= BIT6;
                    P1SEL1 |= BIT6;
                    TB0CCTL1 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB0CCR0;
                    tmp.TCCR_PWM = &TB0CCR1;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB0CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                
                case '7':
                    P1DIR |= BIT6;
                    P1SEL1 |= BIT6;
                    TB0CCTL2 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB0CCR0;
                    tmp.TCCR_PWM = &TB0CCR2;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB0CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                
                default:
                    tmp = __null_PWM_struct__();
                    break; 
            }
            break;

            case '2':
            switch(*(PIN+3)){
                case '0':
                    P2DIR |= BIT0;
                    P2SEL0 |= BIT0;
                    TB1CCTL1 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB1CCR0;
                    tmp.TCCR_PWM = &TB1CCR1;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB1CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                case '1':
                    P2DIR |= BIT1;
                    P2SEL0 |= BIT1;
                    TB1CCTL2 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB1CCR0;
                    tmp.TCCR_PWM = &TB1CCR2;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB1CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                default:
                    tmp = __null_PWM_struct__();
                    break;
            }
            break;
        case '5':
            switch(*(PIN+3)){
                case '0':
                    P5DIR |= BIT0;
                    P5SEL0 |= BIT0;
                    TB2CCTL1 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB2CCR0;
                    tmp.TCCR_PWM = &TB2CCR1;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB2CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                
                case '1':
                    P5DIR |= BIT1;
                    P5SEL0 |= BIT1;
                    TB2CCTL2 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB2CCR0;
                    tmp.TCCR_PWM = &TB2CCR2;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB2CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                default:
                    tmp = __null_PWM_struct__();
            }
            break;
        case '6':
            switch (*(PIN+3)){
                case '0':
                    P6DIR |= BIT0;
                    P6SEL0 |= BIT0;
                    TB3CCTL1 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB3CCR0;
                    tmp.TCCR_PWM = &TB3CCR1;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB3CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                case '1':
                    P6DIR |= BIT1;
                    P6SEL0 |= BIT1;
                    TB3CCTL2 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB3CCR0;
                    tmp.TCCR_PWM = &TB3CCR2;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB3CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;

                case '2':
                    P6DIR |= BIT2;
                    P6SEL0 |= BIT2;
                    TB3CCTL3 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB3CCR0;
                    tmp.TCCR_PWM = &TB3CCR3;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB3CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                case '3':
                    P6DIR |= BIT3;
                    P6SEL0 |= BIT3;
                    TB3CCTL4 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB3CCR0;
                    tmp.TCCR_PWM = &TB3CCR4;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB3CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                case '4':
                    P6DIR |= BIT4;
                    P6SEL0 |= BIT4;
                    TB3CCTL5 = OUTMOD_7;
                    
                    tmp.TCCR_Period = &TB3CCR0;
                    tmp.TCCR_PWM = &TB3CCR4;
                    *tmp.TCCR_PWM = actual_PWM;
                    *tmp.TCCR_Period = actual_Period;

                    TB3CTL = TBSSEL_1 | MC_1 | TBCLR;
                    break;
                default:
                    tmp = __null_PWM_struct__();
            }
            break;
        default:
            tmp = __null_PWM_struct__();
    }
    
    return tmp;
}

void Adjust_DutyCycle(float DUTY, struct PWM_PIN tmp){
    *tmp.TCCR_PWM = (unsigned int)((DUTY)*(*tmp.TCCR_Period));
    if(*tmp.TCCR_PWM > *tmp.TCCR_Period) *tmp.TCCR_PWM = *tmp.TCCR_Period;
}

void Adjust_Period(float ms, struct PWM_PIN tmp){
    float tmp2 = ((float)*tmp.TCCR_PWM) / ((float)*tmp.TCCR_Period);

    (32.768*ms > 0.1) ? (*tmp.TCCR_Period = (unsigned int)(32.768*ms)) : (*tmp.TCCR_Period = 4);
    if (*tmp.TCCR_Period == 1) (*tmp.TCCR_Period = 2);

    *tmp.TCCR_PWM = (unsigned int)(tmp2 * (*tmp.TCCR_Period));
}

void Adjust_PWM(int DUTY, float period, struct PWM_PIN tmp){

    float DUTYtmp = (float)DUTY / 100.0;
    float actual_Period = 32.768*period;
    if(actual_Period < 2 ) actual_Period = 2;

    float actual_PWM = (DUTYtmp*actual_Period);
    if(actual_PWM > actual_Period) actual_PWM = actual_Period;
    if(DUTY >= 100)actual_PWM = actual_Period + 1;

    *tmp.TCCR_Period = (unsigned int)actual_Period;
    *tmp.TCCR_PWM    = (unsigned int)actual_PWM;
}

PWM __null_PWM_struct__(){
    PWM tmp;
    tmp.TCCR_Period = &__absolute_trash__;
    tmp.TCCR_PWM =    &__absolute_trash__;
    return tmp;
}
