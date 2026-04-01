#include "Fiat.h"

Fiat::Fiat()
{
    fuelCapacity = 45;
    fuelConsumption = 6;

    avgSpeedRain = 70;
    avgSpeedSunny = 90;
    avgSpeedSnow = 50;
}

const char* Fiat::GetName()
{
    return "Fiat";
}