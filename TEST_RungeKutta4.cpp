#include <iostream>

#include "RungeKutta4.h"

// Differential equation y' = f(x,y) = y
double f(double x, double y)
{
    return y;
}

// Differential equation y' = g(x,y) = -y
double g(double x, double y)
{
    return -y;
}

// Differential equation y' = g(x,y) = -x^2y+1/y
double h(double x, double y)
{
    return -x*x*y+1/y;
}


int main()
{
    double xmax(5);
    double dx(0.5);
    
    RungeKutta4 RK4(f,dx);
    
    double xn(0);
    double yn(1);
    
    while (xn < xmax)
    {
        std::cout << xn << ' ' << yn << std::endl;
        
        yn = RK4.step(xn,yn);
        xn += dx;
    }
    
    return 0;
}