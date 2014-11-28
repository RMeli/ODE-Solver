#include "ExplicitIntegrator.h"

ExplicitIntegrator::ExplicitIntegrator(double (*ODE_)(double,double), double dx_)
: Integrator(ODE_,dx_)
{}
