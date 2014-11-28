#include "../ImplicitIntegrators/ImplicitMidpoint.h"
#include "testfunction.h"

#include <iostream>

int main()
{
    double xmax(5);
    
    double dx(0.5);
    double xn(0);
    double yn(1);
    
    ImplicitMidpoint IM(f,dx,df);
    
    while (xn < xmax)
    {
        std::cout << xn << ' ' << yn << std::endl;
        
        yn = IM.step(xn,yn);
        xn += dx;
    }
    
    return 0;
}