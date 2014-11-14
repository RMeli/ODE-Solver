#include "ImplicitIntegrator.h"

ImplicitIntegrator::ImplicitIntegrator(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double))
: ODE(ODE_), dODE(dODE_), dx(dx_)
{}

double ImplicitIntegrator::get_dx() const
{
    return dx;
}

ImplicitIntegrator::~ImplicitIntegrator()
{}