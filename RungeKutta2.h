#ifndef RUNGEKUTTA2_H
#define RUNGEKUTTA2_H

#include "Integrator.h"

class RungeKutta2 : public Integrator
{
public:
    RungeKutta2(double (*ODE_)(double,double), double dx_);
    
    double step(double xn, double yn) const;
};

#endif