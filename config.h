#ifndef CONFIG_H
#define CONFIG_H

//==============================
// Falcon FC V1
//==============================

#define FIRMWARE_NAME      "Falcon FC"
#define FIRMWARE_VERSION   "V1.0"

//==============================
// Status LED
//==============================

#define LED_PIN            48

//==============================
// Battery ADC
//==============================

#define BATTERY_PIN        1

//==============================
// PWM Pins
//==============================

#define MOTOR1_PIN         4
#define MOTOR2_PIN         5
#define MOTOR3_PIN         6
#define MOTOR4_PIN         7

//==============================
// PWM
//==============================

#define PWM_FREQ           20000
#define PWM_RESOLUTION     8

// ESP32 LEDC Channels
#define CH_M1              0
#define CH_M2              1
#define CH_M3              2
#define CH_M4              3

//==============================
// Battery Divider
//==============================

// Adjust after calibration
#define ADC_REFERENCE      3.3
#define ADC_MAX            4095.0

#endif
