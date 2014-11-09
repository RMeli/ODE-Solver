#include "NewtonMethod.h"

#include <iostream>

double f(double x, double y) // The solution f(x,y) = 0 is sqrt(2).
{
    return y*y - 2;
}

double df(double x, double y)
{
    return 2*y;
}

double g(double x, double y) // The solution f(x,y) = 0 is sqrt(3).
{
    return y*y - 3;
}

double dg(double x, double y)
{
    return 2*y;
}

int main()
{
    NewtonMethod NM(1.,0.,f,df);
    
    std::cout << NM.solve() << std::endl;
    
    // Change the function to solve
    NM.set_function(g,dg);
    
    std::cout << NM.solve() << std::endl;
    
    return 0;
}