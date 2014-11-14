#include "NewtonMethod.h"

#include "Exception.h"

#include <cmath>
#include <stdexcept>

NewtonMethod::NewtonMethod(double y0_, Function* F_, double tol_, int maxiter_)
: F(F_), y0(y0_), tol(tol_), maxiter(maxiter_)
{}

double NewtonMethod::solve() const
{
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
        
        derivative = F->df(yold);
        
        if ( std::abs(derivative) < 1e-30 )
        {
            throw std::overflow_error("Divide by zero exception.");
        }
        
        ynew = yold - F->f(yold) / derivative;
        
        iter++;
        
    } while( std::abs(ynew-yold) > tol );
    
    return ynew;
}

void NewtonMethod::set(double y0_, Function* F_, double tol_, int maxiter_)
{
    y0 = y0_;
    F = F_;
    tol = tol_;
    maxiter = maxiter_;
}