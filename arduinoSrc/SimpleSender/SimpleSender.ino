/*
 * SimpleSender.cpp
 *
 *  Demonstrates sending IR codes in standard format with address and command
 *  An extended example for sending can be found as SendDemo.
 *
 *  Copyright (C) 2020-2022  Armin Joachimsmeyer
 *  armin.joachimsmeyer@gmail.com
 *
 *  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
 *
 *  MIT License
 */
#include <Arduino.h>

#define DISABLE_CODE_FOR_RECEIVER // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.
//#define SEND_PWM_BY_TIMER         // Disable carrier PWM generation in software and use (restricted) hardware PWM.
//#define USE_NO_SEND_PWM           // Use no carrier PWM, just simulate an active low receiver signal. Overrides SEND_PWM_BY_TIMER definition
#define numCommands 10

#include "PinDefinitionsAndMore.h" // Define macros for input and output pin etc.
#include <IRremote.hpp>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
    Serial.print(F("Send IR signals at pin "));
    Serial.println(IR_SEND_PIN);

    /*
     * The IR library setup. That's all!
     */
//    IrSender.begin(); // Start with IR_SEND_PIN as send pin and if NO_LED_FEEDBACK_CODE is NOT defined, enable feedback LED at default feedback LED pin
    IrSender.begin(DISABLE_LED_FEEDBACK); // Start with IR_SEND_PIN as send pin and disable feedback LED at default feedback LED pin
}

/*
 * Set up the data to be sent.
 * For most protocols, the data is build up with a constant 8 (or 16 byte) address
 * and a variable 8 bit command.
 * There are exceptions like Sony and Denon, which have 5 bit address.
 */
uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

//fan IR signals
uint32_t on[]={0x20C0488, 0x8E06000A};
uint32_t off[]={0x20C0408, 0xE06000A};
uint32_t med[]={0x820C0488, 0xE06000A};
uint32_t high[]={0x420C0488, 0xCE06000A};
uint32_t eco[]={0xC20C0488, 0x4E06000A};
uint32_t low[]={0x20C0488, 0x8E06000A};
uint32_t rLow[]={0x28C0488, 0xE06000A};
uint32_t rMed[]={0x828C0488, 0x8E06000A};
uint32_t rHigh[]={0x428C0488, 0x4E06000A};
uint32_t rEco[]={0xC28C0488, 0xCE06000A};

//grouping signals into array
uint32_t* controlArray[numCommands]{
  on,    //0
  off,   //1
  eco,   //2
  low,   //3
  med,   //4
  high,  //5
  rEco,  //6
  rLow,  //7
  rMed,  //8
  rHigh  //9
};

int incomingByte = 0; // for incoming serial data

void loop() {

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    for(int i=0;i<numCommands;i++){ //check serial input against range of commandArray
      if((incomingByte-48)==i){ //ascii offset

        Serial.print(i);
        Serial.println();

        IrSender.sendPulseDistanceWidthFromArray(38, 9200, 4800, 550, 1650, 550, 600, &controlArray[i][0], 64, PROTOCOL_IS_LSB_FIRST, 100, 0);
        delay(100);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
      }
    }
  }

}
