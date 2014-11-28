#include "../NumericalMethods/NewtonMethod.h"
#include "../Utilities/Function.h"

#include <iostream>

class MyFunction1 : public Function
{
public:
    double f(double y)
    {
        return y*y - 2;
    }
    
    double df(double y)
    {
        return 2*y;
    }
};

class MyFunction2 : public Function
{
public:
    double f(double y)
    {
        return y*y - 3;
    }
    double df(double y)
    {
        return 2*y;
    }
};

int main()
{
    double y0(1);
    
    MyFunction1* F1(new MyFunction1);
    MyFunction2* F2(new MyFunction2);
    
    NewtonMethod NM(y0,F1);
    
    std::cout << NM.solve() << std::endl;
    
    // Change the function to solve
    NM.set(y0,F2);
    
    std::cout << NM.solve() << std::endl;
    
    return 0;
}