#include <Arduino.h>

#include "config.h"
#include "system.h"

//==================================
// Timing
//==================================

unsigned long previousBlink=0;
unsigned long previousBattery=0;
unsigned long previousLoop=0;

void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println();
    Serial.println(FIRMWARE_NAME);
    Serial.println(FIRMWARE_VERSION);

    initLED();

    initBattery();

    initPWM();

    Serial.println("Initialization Complete");
}

void loop()
{
    unsigned long now=millis();

    //-----------------------------
    // Blink LED every 500ms
    //-----------------------------

    if(now-previousBlink>=500)
    {
        previousBlink=now;

        blinkLED();
    }

    //-----------------------------
    // Read Battery every second
    //-----------------------------

    if(now-previousBattery>=1000)
    {
        previousBattery=now;

        float battery=readBatteryVoltage();

        Serial.print("Battery ADC Voltage : ");

        Serial.println(battery,3);
    }

    //-----------------------------
    // Measure Loop Time
    //-----------------------------

    unsigned long currentMicros=micros();

    unsigned long loopTime=currentMicros-previousLoop;

    previousLoop=currentMicros;

    Serial.print("Loop Time : ");

    Serial.print(loopTime);

    Serial.println(" us");

    delay(10);
}
