#ifndef RUNGEKUTTA4_H
#define RUNGEKUTTA4_H

#include "Integrator.h"

class RungeKutta4 : public Integrator
{
public:
    RungeKutta4(double (*ODE_)(double,double), double dx_);
    
    double step(double xn, double yn) const;
};

#endif