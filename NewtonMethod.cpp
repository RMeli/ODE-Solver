#include "NewtonMethod.h"

#include "Exception.h"

#include <cmath>
#include <stdexcept>

NewtonMethod::NewtonMethod(double y0_, double (*f_)(double), double (*df_)(double), double tol_, int maxiter_)
: f(f_), df(df_), y0(y0_), tol(tol_), maxiter(maxiter_)
{}

double NewtonMethod::solve() const
{
    if (f == nullptr or df == nullptr)
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
        
        derivative = df(yold);
        
        if ( std::abs(derivative) < 1e-12 )
        {
            throw std::overflow_error("Divide by zero exception.");
        }
        
        ynew = yold - f(yold) / derivative;
        
        iter++;
        
    } while( std::abs(ynew-yold) > tol );
    
    return ynew;
}

void NewtonMethod::set(double y0_, double (*f_)(double), double (*df_)(double), double tol_, int maxiter_)
{
    y0 = y0_;
    f = f_;
    df = df_;
    tol = tol_;
    maxiter = maxiter_;
}