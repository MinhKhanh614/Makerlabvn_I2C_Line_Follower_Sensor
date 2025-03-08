#include "Makerlabvn_I2C_Line_Follower_Sensor.h"
#include <MKL_LiquidCrystal_I2C.h>

Makerlabvn_I2C_Line_Follower_Sensor LineFollowSensor;
MKL_LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    LineFollowSensor.setup();
}

void loop()
{
    LineFollowSensor.getData();
    /****** THỨ TỰ SENSOR ******/
    /*-------------------------*/
    /* |TRÁI| 1 2 3 4 5 |PHẢI| */
    /*-------------------------*/

    String values[5];
    for (int i = 0; i < 5; i++)
    {
        values[i] = String(LineFollowSensor.getValue(i));
    }

    // Hiển thị giá trị trên LCD
    lcd.setCursor(0, 0); // Chọn dòng 1, cột 0
    for (int i = 0; i < 3; i++)
    {
        lcd.print(values[i]); // Hiển thị 3 giá trị đầu
        lcd.print(" ");       // Dấu cách giữa các giá trị
    }

    lcd.setCursor(0, 1); // Chọn dòng 2, cột 0
    for (int i = 3; i < 5; i++)
    {
        lcd.print(values[i]); // Hiển thị 2 giá trị còn lại
        lcd.print(" ");       // Dấu cách giữa các giá trị
    }

    for (int i = 0; i < 5; i++)
    {
        Serial.print(LineFollowSensor.getValue(i));
        Serial.print("\t");
    }
    Serial.println();

    delay(100);
}