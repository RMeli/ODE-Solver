#ifndef TESTFUNCTION_H
#define TESTFUNCTION_H

#include <cmath>

double f(double x, double y)
{
    return -std::sin(x);
}

double df(double x, double y)
{
    return -std::cos(x);
}

double s(double x)
{
    return std::sin(x);
}

#endif