#pragma once

constexpr long double operator"" _Kelvin(long double value)
{
    return value - 273.15;
}

constexpr long double operator"" _Kelvin(unsigned long long value)
{
    return (long double)value - 273.15;
}

constexpr long double operator"" _Fahrenheit(long double value)
{
    return (value - 32.0) * 5.0 / 9.0;
}

constexpr long double operator"" _Fahrenheit(unsigned long long value)
{
    return ((long double)value - 32.0) * 5.0 / 9.0;
}