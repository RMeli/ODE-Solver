#include <iostream>

#include "../ExplicitIntegrators/RungeKutta2.h"
#include "testfunction.h"

int main()
{
    double xmax(5);
    double dx(0.5);
    
    RungeKutta2 RK2(f,dx);
    
    double xn(0);
    double yn(1);
    
    while (xn < xmax)
    {
        std::cout << xn << ' ' << yn << std::endl;
        
        yn = RK2.step(xn,yn);
        xn += dx;
    }
    
    return 0;
}