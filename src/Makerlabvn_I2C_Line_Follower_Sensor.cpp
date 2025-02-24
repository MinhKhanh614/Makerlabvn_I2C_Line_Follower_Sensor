#include "Makerlabvn_I2C_Line_Follower_Sensor.h"

void Makerlabvn_I2C_Line_Follower_Sensor::setup()
{
    Wire.begin();
    kxnTaskManager.add(this);
    setState(KXN_TASK_STATE_START);
}

void Makerlabvn_I2C_Line_Follower_Sensor::loop()
{
    Wire.requestFrom(SENSOR_ADDRESS, MAKERLABVN_I2C_LINE_FOLLOWER_SENSOR_BUFFER_SIZE);
    for (int i = 0; i < MAKERLABVN_I2C_LINE_FOLLOWER_SENSOR_BUFFER_SIZE; i++)
    {
        readValue[i] = Wire.read();
    }
    kDelay(10);
}

void Makerlabvn_I2C_Line_Follower_Sensor::getData()
{
    run(millis());
}

int Makerlabvn_I2C_Line_Follower_Sensor::getValue(uint8_t index)
{
    return readValue[index];
}