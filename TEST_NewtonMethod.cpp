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

int main()
{
    NewtonMethod NM(f,df,1.,0.,1e-6);
    
    std::cout << NM.solve() << std::endl;
    
    return 0;
}