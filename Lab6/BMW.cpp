#include "BMW.h"

BMW::BMW()
{
    fuelCapacity = 65;
    fuelConsumption = 8;

    avgSpeedRain = 90;
    avgSpeedSunny = 120;
    avgSpeedSnow = 70;
}

const char* BMW::GetName()
{
    return "BMW";
}