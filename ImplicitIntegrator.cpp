#include "ImplicitIntegrator.h"

ImplicitIntegrator::ImplicitIntegrator(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double))
: ODE(ODE_), dx(dx_), dODE(dODE_)
{}

double ImplicitIntegrator::get_dx() const
{
    return dx;
}

ImplicitIntegrator::~ImplicitIntegrator()
{}