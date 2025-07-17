/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F46K20
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ADC aliases
#define ADC_TRIS                 TRISAbits.TRISA0
#define ADC_LAT                  LATAbits.LATA0
#define ADC_PORT                 PORTAbits.RA0
#define ADC_ANS                  ANSELbits.ANS0
#define ADC_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ADC_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ADC_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ADC_GetValue()           PORTAbits.RA0
#define ADC_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ADC_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ADC_SetAnalogMode()      do { ANSELbits.ANS0 = 1; } while(0)
#define ADC_SetDigitalMode()     do { ANSELbits.ANS0 = 0; } while(0)

// get/set Servo aliases
#define Servo_TRIS                 TRISDbits.TRISD0
#define Servo_LAT                  LATDbits.LATD0
#define Servo_PORT                 PORTDbits.RD0
#define Servo_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define Servo_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define Servo_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define Servo_GetValue()           PORTDbits.RD0
#define Servo_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define Servo_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)

// get/set Status_Controll aliases
#define Status_Controll_TRIS                 TRISDbits.TRISD4
#define Status_Controll_LAT                  LATDbits.LATD4
#define Status_Controll_PORT                 PORTDbits.RD4
#define Status_Controll_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define Status_Controll_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define Status_Controll_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define Status_Controll_GetValue()           PORTDbits.RD4
#define Status_Controll_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define Status_Controll_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/