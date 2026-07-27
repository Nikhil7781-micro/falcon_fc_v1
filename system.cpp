#include <Arduino.h>
#include "config.h"
#include "system.h"

void initLED()
{
    pinMode(LED_PIN,OUTPUT);
    digitalWrite(LED_PIN,LOW);
}

void blinkLED()
{
    static bool state=false;

    state=!state;

    digitalWrite(LED_PIN,state);
}

void initBattery()
{
    pinMode(BATTERY_PIN,INPUT);
}

float readBatteryVoltage()
{
    int adc=analogRead(BATTERY_PIN);

    float voltage=(adc*ADC_REFERENCE)/ADC_MAX;

    return voltage;
}

void initPWM()
{
    ledcAttach(MOTOR1_PIN,PWM_FREQ,PWM_RESOLUTION);
    ledcAttach(MOTOR2_PIN,PWM_FREQ,PWM_RESOLUTION);
    ledcAttach(MOTOR3_PIN,PWM_FREQ,PWM_RESOLUTION);
    ledcAttach(MOTOR4_PIN,PWM_FREQ,PWM_RESOLUTION);

    ledcWrite(MOTOR1_PIN,0);
    ledcWrite(MOTOR2_PIN,0);
    ledcWrite(MOTOR3_PIN,0);
    ledcWrite(MOTOR4_PIN,0);
}
