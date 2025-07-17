/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F46K20
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

void myServoISR(void);
    
unsigned char servocounter = 0;                                                 // definiert "servocounter"
uint16_t adc_wert;                                                              // definiert "adc_wert"

/*
                         Main application
 */
void main(void){
    // Initialize the device
    SYSTEM_Initialize();
    ADC_Initialize();
    TMR1_SetInterruptHandler (myServoISR);                  //Define interrupt Handler

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    __delay_ms(1000);                                                           // warte 1s
    Status_Controll_SetHigh();                                                  // setzt "Controll_SetHigh" auf 1
    
    while (1){                                                                  // Endlosscheife
        ADC_SelectChannel(ADC);                                                 // wählt "ADC" als ADC-Port aus
        ADC_StartConversion();                                                  // Startet ADC-Prozess
        ADC_TemperatureAcquisitionDelay();                                      // Wartezeit zum Einschwigen
        //adc_wert = (uint16_t)(ADC_GetConversionResult() / 4);                 // schreibt den Wert von "adc" in "adc_wert"
        adc_wert = (uint16_t)(ADC_GetConversionResult() / 8);                 // schreibt den Wert von "adc" in "adc_wert"
        servocounter = (char)adc_wert;                                          // schreibt den Wert von "adc_wert" in "servocounter"
    }                                                                           // 
}                                                                               // 

void myServoISR(void){                                                          // "myServoISR" (18ms))
    Servo_SetHigh();                                                            // setzt "Servo" auf 1
    __delay_ms(1);                                                              // warte 1ms
    for(int i = 0; i < servocounter; i++){                                      // wiederhole solange bis "i" wie "servocounter" ist
        __delay_us(7);                                                          // warte 7us
    }                                                                           // 
    Servo_SetLow();                                                             // setzt "Servo" auf 0
}                                                                               // 
/**
 End of File
*/