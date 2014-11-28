#include "ImplicitIntegrator.h"

ImplicitIntegrator::ImplicitIntegrator(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double))
: Integrator(ODE_,dx_), dODE(dODE_)
{}