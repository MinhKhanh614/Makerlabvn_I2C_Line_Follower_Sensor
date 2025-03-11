#include "kxnTaskShowValueSensor.h"

kxnTaskShowValueSensor kxnTaskShowValueSensor1;

void setup()
{
    kxnTaskShowValueSensor1.setup();
}

void loop()
{
    kxnTaskManager.run(millis());
}