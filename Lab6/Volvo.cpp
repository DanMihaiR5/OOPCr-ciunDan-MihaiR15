#include "Volvo.h"

Volvo::Volvo()
{
    fuelCapacity = 60;
    fuelConsumption = 6;

    avgSpeedRain = 80;
    avgSpeedSunny = 100;
    avgSpeedSnow = 60;
}

const char* Volvo::GetName()
{
    return "Volvo";
}