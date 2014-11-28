#include <iostream>

#include "../ExplicitIntegrators/EulerIntegrator.h"
#include "testfunction.h"

int main()
{
    double xmax(5);
    double dx(0.05);
    
    EulerIntegrator E(f,dx);
    
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