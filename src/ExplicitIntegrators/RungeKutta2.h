#ifndef RUNGEKUTTA2_H
#define RUNGEKUTTA2_H

#include "../Integrators/ExplicitIntegrator.h"

//! RungeKutta2 class.
/*!
 Perform one step of the explicit Runge Kutta method of order 2.
 */
class RungeKutta2 : public ExplicitIntegrator
{
public:
    //! Constructor.
    /*!
     Take the ODE to integrate and the step lenght as arguemnts.
     */
    RungeKutta2(double (*ODE_)(double,double), double dx_);
    
    //! Integrating function.
    /*!
     Perform a step of lenght dx starting from xn and yn, calculating y(n+1) that obviosuly corresponds to xn+dx.
     */
    double step(double xn, double yn);
};

#endif