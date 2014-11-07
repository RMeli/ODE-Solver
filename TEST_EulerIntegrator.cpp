#include <iostream>

#include "EulerIntegrator.h"

// Differential equation y' = f(x,y) = y
double f(double x, double y)
{
    return y;
}

// Differential equation y' = g(x,y) = -2.3y
double g(double x, double y)
{
    return -2.3*y;
}

// Differential equation y' = g(x,y) = -xy
double h(double x, double y)
{
    return -x*x*y+1/y;
}


int main()
{
    double xmax(5);
    double dx(0.01);
    
    EulerIntegrator E(h,dx);
    
    double xn(0);
    double yn(1);
    
    while (xn < xmax)
    {
        std::cout << xn << ' ' << yn << std::endl;
        
        yn = E.step(xn,yn);
        xn += dx;
    }
    
    return 0;
}