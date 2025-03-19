#include "HardwareSerial.h"
#include "Makerlabvn_I2C_Line_Follower_Sensor.h"

void Makerlabvn_I2C_Line_Follower_Sensor::setup(uint8_t paAddress, uint8_t paCountSensor)
{
    countSensor = paCountSensor;
    address = paAddress;
    Wire.begin();
    kxnTaskManager.add(this);
    setState(KXN_TASK_STATE_START);
    setBlack();
}
void Makerlabvn_I2C_Line_Follower_Sensor::setup(uint8_t input_address)
{
    this->address = input_address;
    Wire.begin();
    kxnTaskManager.add(this);
    setState(KXN_TASK_STATE_START);
}

void Makerlabvn_I2C_Line_Follower_Sensor::loop()
{
<<<<<<< HEAD
    Wire.requestFrom(address, MAKERLABVN_I2C_LINE_FOLLOWER_SENSOR_BUFFER_SIZE);
=======
    Wire.requestFrom(this->address, MAKERLABVN_I2C_LINE_FOLLOWER_SENSOR_BUFFER_SIZE);
>>>>>>> 4a5ad13b640970a9daa05f81b108e285aa147bfa
    for (int i = 0; i < MAKERLABVN_I2C_LINE_FOLLOWER_SENSOR_BUFFER_SIZE; i++)
    {
        readValue[i] = Wire.read();
    }
<<<<<<< HEAD
    // Serial.println("KDEBUG DELAY");
=======
    if(!isBlack)
    {
        readValue[countSensor] = (readValue[countSensor] ^ 0b11111) & 0b11111;
    }
>>>>>>> 4a5ad13b640970a9daa05f81b108e285aa147bfa
    kDelay(10);
}

void Makerlabvn_I2C_Line_Follower_Sensor::getData()
{
    run(millis());
}

<<<<<<< HEAD
uint8_t Makerlabvn_I2C_Line_Follower_Sensor::getValue(uint8_t index)
=======
uint8_t Makerlabvn_I2C_Line_Follower_Sensor::getValue()
{
    return readValue[countSensor];
}

uint8_t Makerlabvn_I2C_Line_Follower_Sensor::getValue(uint8_t index)
{
    return (readValue[countSensor] >> index) & 0x01;
}

uint8_t Makerlabvn_I2C_Line_Follower_Sensor::getRawValue(uint8_t index)
>>>>>>> 4a5ad13b640970a9daa05f81b108e285aa147bfa
{
    return readValue[index];
}

uint8_t Makerlabvn_I2C_Line_Follower_Sensor::getThresHoldValue(uint8_t index)
{
    return readValue[countSensor + index + 1];
}

void Makerlabvn_I2C_Line_Follower_Sensor::setI2C_Address(uint8_t paAdd)
{
    if(paAdd >= 127) return;
    delay(5);
    Wire.beginTransmission(this->address); // transmit to device #8
    Wire.write(1);        // send id
    Wire.write(0);              // send cmd
    Wire.write(0);              // send len
    Wire.write(paAdd);              // send value
    Wire.endTransmission();    // stop transmitting

    this->address = paAdd;
    Wire.begin(paAdd);
}