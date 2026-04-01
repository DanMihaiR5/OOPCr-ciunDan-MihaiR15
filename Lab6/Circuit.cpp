#include "Circuit.h"
#include <iostream>

void Circuit::SetLength(int l)
{
    length = l;
}

void Circuit::SetWeather(Weather w)
{
    weather = w;
}

void Circuit::AddCar(Car* car)
{
    cars[carsCount++] = car;
}

void Circuit::Race()
{
    for (int i = 0; i < carsCount; i++)
    {
        int maxDistance =
            (cars[i]->GetFuelCapacity() / cars[i]->GetFuelConsumption()) * 100;

        if (maxDistance < length)
        {
            finished[i] = false;
        }
        else
        {
            finished[i] = true;
            finishTimes[i] =
                (float)length / cars[i]->GetSpeed(weather);
        }
    }
}

void Circuit::ShowFinalRanks()
{
    for (int i = 0; i < carsCount - 1; i++)
        for (int j = i + 1; j < carsCount; j++)
            if (finishTimes[i] > finishTimes[j])
            {
                float t = finishTimes[i];
                finishTimes[i] = finishTimes[j];
                finishTimes[j] = t;

                Car* c = cars[i];
                cars[i] = cars[j];
                cars[j] = c;
            }

    for (int i = 0; i < carsCount; i++)
        if (finished[i])
            std::cout << cars[i]->GetName() << " finished in "
                      << finishTimes[i] << " hours\n";
}

void Circuit::ShowWhoDidNotFinish()
{
    for (int i = 0; i < carsCount; i++)
        if (!finished[i])
            std::cout << cars[i]->GetName() << " did not finish\n";
}