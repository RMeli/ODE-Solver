#include "EulerIntegrator.h"

EulerIntegrator::EulerIntegrator(double (*ODE_)(double,double), double dx_ = 1.e-3)
: Integrator(ODE_,dx_)
{}

double EulerIntegrator::step(double xn, double yn) const
{
    return yn + dx * ODE(xn,yn);
}