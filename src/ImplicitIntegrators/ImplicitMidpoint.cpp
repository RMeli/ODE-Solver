#include "ImplicitMidpoint.h"
#include "../NumericalMethods/NewtonMethod.h"

ImplicitMidpoint::ImplicitMidpoint(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double))
: ImplicitIntegrator(ODE_,dx_, dODE_), IMF(new IMFunction(this))
{}

double ImplicitMidpoint::step(double xn, double yn)
{
    xnew = xn + 0.5 * dx;
    yold = yn;
    
    NewtonMethod NM(yold,IMF);
    
    return NM.solve();
}

ImplicitMidpoint::IMFunction::IMFunction(ImplicitMidpoint* IM_)
: IM(IM_)
{}

double ImplicitMidpoint::IMFunction::f(double yn)
{
    return yn - IM->yold - IM->dx * IM->ODE(IM->xnew, 0.5 * (IM->yold + yn));
}

double ImplicitMidpoint::IMFunction::df(double yn)
{
    return 1 - IM->dx * IM->dODE(IM->xnew, 0.5 * (IM->yold + yn)) * 0.5;
}

ImplicitMidpoint::~ImplicitMidpoint()
{
    delete IMF;
}