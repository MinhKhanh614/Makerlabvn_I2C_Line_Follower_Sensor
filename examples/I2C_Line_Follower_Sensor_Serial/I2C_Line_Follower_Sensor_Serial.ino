#include "Makerlabvn_I2C_Line_Follower_Sensor.h"

Makerlabvn_I2C_Line_Follower_Sensor LineFollowSensor;

void setup()
{
    Serial.begin(9600);
    LineFollowSensor.setup();
}

void loop()
{
    /****** THỨ TỰ SENSOR ******/
    /*-------------------------*/
    /* |TRÁI| 1 2 3 4 5 |PHẢI| */
    /*-------------------------*/

    Serial.print("Sensor 1 Value: ");
    Serial.println(LineFollowSensor.getValue(0));
    // Serial.print("Sensor 2 Value: ");
    // Serial.println(LineFollowSensor.getValue(1));
    // Serial.print("Sensor 3 Value: ");
    // Serial.println(LineFollowSensor.getValue(2));
    // Serial.print("Sensor 4 Value: ");
    // Serial.println(LineFollowSensor.getValue(3));
    // Serial.print("Sensor 5 Value: ");
    // Serial.println(LineFollowSensor.getValue(4));
    LineFollowSensor.getData();
    delay(50);
}