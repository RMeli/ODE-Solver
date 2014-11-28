#include <iostream>

#include "../ExplicitIntegrators/RungeKutta4.h"
#include "testfunction.h"

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