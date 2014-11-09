#include "Integrator.h"

Integrator::Integrator(double (*ODE_)(double,double), double dx_)
: ODE(ODE_), dx(dx_)
{}

double Integrator::get_dx() const
{
    return dx;
}

Integrator::~Integrator()
{}