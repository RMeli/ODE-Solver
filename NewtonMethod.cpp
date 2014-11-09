#include "NewtonMethod.h"

#include "Exception.h"

#include <cmath>
#include <stdexcept>

NewtonMethod::NewtonMethod(double y0_, double x_, double (*fxy_)(double,double), double (*dyfxy_)(double,double), double tol_, int maxiter_)
: fxy(fxy_), dyfxy(dyfxy_), y0(y0_), x(x_), tol(tol_), maxiter(maxiter_)
{}

double NewtonMethod::solve() const
{
    if (fxy == nullptr or dyfxy == nullptr)
    {
        throw Undefined();
    }
    
    double yold(y0);
    double ynew(y0);
    
    double derivative(0);
    
    double iter(0);
    
    do {
        if (iter > maxiter)
        {
            throw std::overflow_error("Maximum iterations reached. Convergence not reached.");
        }
        
        yold = ynew;
        
        derivative = dyfxy(x,yold);
        
        if ( std::abs(derivative) < 1e-12 )
        {
            throw std::overflow_error("Divide by zero exception.");
        }
        
        ynew = yold - fxy(x,yold) / derivative;
        
        iter++;
        
    } while( std::abs(ynew-yold) > tol );
    
    return ynew;
}

void NewtonMethod::set_function(double (*f)(double,double), double (*df)(double,double))
{
    fxy = f;
    dyfxy = df;
    
}

void NewtonMethod::set_tol(double tol_)
{
    tol = tol_;
}

void NewtonMethod::set_maxiter(int maxiter_)
{
    maxiter = maxiter_;
}