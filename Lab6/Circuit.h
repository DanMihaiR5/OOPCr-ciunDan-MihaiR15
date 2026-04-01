#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
    Car* cars[10];
    int carsCount = 0;

    int length;
    Weather weather;

    float finishTimes[10];
    bool finished[10];

public:
    void SetLength(int l);
    void SetWeather(Weather w);
    void AddCar(Car* car);

    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};