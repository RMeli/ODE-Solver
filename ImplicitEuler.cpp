#include "ImplicitEuler.h"

ImplicitEuler::ImplicitEuler(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double))
: ImplicitIntegrator(ODE_,dx_, dODE_)
{}

double ImplicitEuler::step(double xn, double yn)
{
    xnew = xn + dx;
    yold = yn;
    
    NM.set(yold,NLF,dNLF);
    
    return NM.solve();
}

double ImplicitEuler::NLF(double yn) const
{
    return yn - dx * ODE(xnew,yn) - yold;
}

double ImplicitEuler::dNLF(double yn) const
{
    return 1 - dx * dODE(xnew,yn);
}