#include "Canvas.h"
#include <iostream>
using namespace std;
int main()
{
    Canvas c(50, 20);

    c.DrawRect(2, 2, 20, 10, '#');
    c.FillRect(25, 3, 35, 8, '@');

    c.DrawCircle(15, 15, 4, '*');
    c.FillCircle(35, 15, 3, '+');

    c.DrawLine(0, 0, 49, 19, '/');

    c.SetPoint(10, 5, 'X');

    c.Print();

    c.Clear();

    return 0;
}