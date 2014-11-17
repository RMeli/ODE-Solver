#include "ImplicitTrapezoidal.h"
#include "NewtonMethod.h"

ImplicitTrapezoidal::ImplicitTrapezoidal(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double))
: ImplicitIntegrator(ODE_,dx_, dODE_), ITF(new ITFunction(this))
{}

double ImplicitTrapezoidal::step(double xn, double yn)
{
    xnew = xn + dx;
    yold = yn;
    
    NewtonMethod NM(yold,ITF);
    
    return NM.solve();
}

ImplicitTrapezoidal::ITFunction::ITFunction(ImplicitTrapezoidal* IT_)
: IT(IT_)
{}

double ImplicitTrapezoidal::ITFunction::f(double yn)
{
    return yn - IT->yold - 0.5 * IT->dx * (IT->ODE(IT->xnew - IT->dx, IT->yold) + IT->ODE(IT->xnew,yn) );
}

double ImplicitTrapezoidal::ITFunction::df(double yn)
{
    return 1 - 0.5 * IT->dx * IT->dODE(IT->xnew,yn);
}

ImplicitTrapezoidal::~ImplicitTrapezoidal()
{
    delete ITF;
}