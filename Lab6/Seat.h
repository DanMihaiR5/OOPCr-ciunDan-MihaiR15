#pragma once
#include "Car.h"

class Seat : public Car
{
public:
    Seat();
    const char* GetName();
};