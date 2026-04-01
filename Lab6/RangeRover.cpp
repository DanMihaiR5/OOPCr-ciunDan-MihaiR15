#include "RangeRover.h"

RangeRover::RangeRover()
{
    fuelCapacity = 80;
    fuelConsumption = 10;

    avgSpeedRain = 85;
    avgSpeedSunny = 110;
    avgSpeedSnow = 80;
}

const char* RangeRover::GetName()
{
    return "RangeRover";
}