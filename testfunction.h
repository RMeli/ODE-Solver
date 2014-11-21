#ifndef TESTFUNCTION_H
#define TESTFUNCTION_H

#include <cmath>

double f(double x, double y)
{
    return -std::sin(y)*y;
}

double df(double x, double y)
{
    return -std::cos(y)*y-std::sin(y);
}

#endif