#include "Seat.h"

Seat::Seat()
{
    fuelCapacity = 50;
    fuelConsumption = 5;

    avgSpeedRain = 75;
    avgSpeedSunny = 95;
    avgSpeedSnow = 55;
}

const char* Seat::GetName()
{
    return "Seat";
}