#ifndef __Makerlabvn_I2C_Line_Follower_Sensor_H__
#define __Makerlabvn_I2C_Line_Follower_Sensor_H__

#include "kxnTask.h"
#include <Wire.h>
#include <Arduino.h>

// #define SENSOR_ADDRESS 0x2A
#define MAKERLABVN_I2C_LINE_FOLLOWER_SENSOR_BUFFER_SIZE 5

CREATE_TASK(Makerlabvn_I2C_Line_Follower_Sensor)

void setup();
void setup(uint8_t address);
void loop();
void getData();
uint8_t getValue(uint8_t index);

private:
uint8_t readValue[MAKERLABVN_I2C_LINE_FOLLOWER_SENSOR_BUFFER_SIZE] = {0, 0, 0, 0, 0};
uint8_t address = 0x2A;
END

#endif