#include "NewtonMethod.h"

#include <iostream>

double f(double y) // The solution f(y) = 0 is sqrt(2).
{
    return y*y - 2;
}

double df(double y)
{
    return 2*y;
}

double g(double y) // The solution f(y) = 0 is sqrt(3).
{
    return y*y - 3;
}

double dg(double y)
{
    return 2*y;
}

int main()
{
    double y0(1);
    
    NewtonMethod NM(y0,f,df);
    
    std::cout << NM.solve() << std::endl;
    
    // Change the function to solve
    NM.set(y0,g,dg);
    
    std::cout << NM.solve() << std::endl;
    
    return 0;
}