#include "RungeKutta2.h"

RungeKutta2::RungeKutta2(double (*ODE_)(double,double), double dx_)
: Integrator(ODE_,dx_)
{}

double RungeKutta2::step(double xn, double yn) const
{
    double k1( ODE(xn,yn) );
    double k2( ODE(xn + dx, yn + dx * k1) );
    
    return yn + dx / 2. * (k1 + k2);
}