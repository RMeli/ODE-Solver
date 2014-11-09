#include "NewtonMethod.h"

#include <cmath>
#include <stdexcept>

NewtonMethod::NewtonMethod(double (*fxy_)(double,double), double (*dyfxy_)(double,double), double y0_, double x_, double tol_)
: fxy(fxy_), dyfxy(dyfxy_), y0(y0_), x(x_), tol(tol_)
{}

double NewtonMethod::solve() const
{
    double yold(y0);
    double ynew(y0);
    
    double derivative(0);
    
    do {
        yold = ynew;
        
        derivative = dyfxy(x,yold);
        
        if ( std::abs(derivative) < 1e-12 )
        {
            throw std::overflow_error("Divide by zero exception.");
        }
        
        ynew = yold - fxy(x,yold) / derivative;
        
    } while( std::abs(ynew-yold) > tol );
    
    return ynew;
}