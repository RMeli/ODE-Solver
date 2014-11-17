#include "ImplicitEuler.h"
#include "NewtonMethod.h"

ImplicitEuler::ImplicitEuler(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double))
: ImplicitIntegrator(ODE_,dx_, dODE_), IEF(new IEFunction(this))
{}

double ImplicitEuler::step(double xn, double yn)
{
    xnew = xn + dx;
    yold = yn;
    
    NewtonMethod NM(yold,IEF);
    
    return NM.solve();
}

ImplicitEuler::IEFunction::IEFunction(ImplicitEuler* IE_)
: IE(IE_)
{}

double ImplicitEuler::IEFunction::f(double yn)
{
    return yn - IE->dx * IE->ODE(IE->xnew,yn) - IE->yold;
}

double ImplicitEuler::IEFunction::df(double yn)
{
    return 1 - IE->dx * IE->dODE(IE->xnew,yn);
}

ImplicitEuler::~ImplicitEuler()
{
    delete IEF;
}