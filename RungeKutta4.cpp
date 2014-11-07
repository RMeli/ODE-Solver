#include "RungeKutta4.h"

RungeKutta4::RungeKutta4(double (*ODE_)(double,double), double dx_ = 1.e-3)
: Integrator(ODE_,dx_)
{}

double RungeKutta4::step(double xn, double yn) const
{
    double dx2(dx/2.);
    
    double k1( ODE(xn,yn) );
    double k2( ODE(xn + dx2, yn + dx2 * k1) );
    double k3( ODE(xn + dx2, yn + dx2 * k2) );
    double k4( ODE(xn  + dx, yn + dx * k3) );
    
    return yn + dx/6. * (k1 + 2*k2 + 2*k3 + k4);
}