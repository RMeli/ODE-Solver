#include "EulerIntegrator.h"

EulerIntegrator::EulerIntegrator(double (*ODE_)(double,double), double dx_)
: ExplicitIntegrator(ODE_,dx_)
{}

double EulerIntegrator::step(double xn, double yn)
{
    return yn + dx * ODE(xn,yn);
}