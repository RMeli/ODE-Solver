#include "Function.h"

#include <iostream>

class Foo
{
public:
    Foo() {}
    
    double f(double x)
    {
        return x;
    }
    
    double df(double x)
    {
        return 1;
    }
};

int main()
{
    Function<Foo> F(&Foo::f,&Foo::df);
    
    for (unsigned int i(0); i < 10; i++)
    {
        std::cout << F.feval(i) << ' ' << F.dfeval(i) << std::endl;
    }
    
    return 0;
}