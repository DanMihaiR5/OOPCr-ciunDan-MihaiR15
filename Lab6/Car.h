#pragma once
#include "Weather.h"

class Car
{
protected:
    int fuelCapacity;
    int fuelConsumption;
    int avgSpeedRain;
    int avgSpeedSunny;
    int avgSpeedSnow;

public:
    virtual const char* GetName() = 0;

    int GetFuelCapacity()
    {
        return fuelCapacity;
    }

    int GetFuelConsumption()
    {
        return fuelConsumption;
    }

    int GetSpeed(Weather w)
    {
        if (w == Weather::Rain) return avgSpeedRain;
        if (w == Weather::Sunny) return avgSpeedSunny;
        return avgSpeedSnow;
    }
};