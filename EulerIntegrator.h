#ifndef EULERINTEGRATOR_H
#define EULERINTEGRATOR_H

#include "Integrator.h"

class EulerIntegrator : public Integrator
{
public:
    EulerIntegrator(double (*ODE_)(double,double), double dx_);
    
    double step(double xn, double yn) const;
};

#endif