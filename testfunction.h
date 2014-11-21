#ifndef TESTFUNCTION_H
#define TESTFUNCTION_H

#include <cmath>

double f(double x, double y)
{
    return -y;
}

double df(double x, double y)
{
    return -1;
}

double s(double x)
{
    return std::exp(-x);
}

#endif