#ifndef EULERINTEGRATOR_H
#define EULERINTEGRATOR_H

#include "../Integrators/ExplicitIntegrator.h"

//! EulerIntegrator class.
/*!
 Perform one step of the explicite Euler method, probably the simplest method to solve ODEs.
 
 This method is of oreder one in dx (step size) and present problems of stability. This method should be used with small step size (pay attention to rounding errors) and only for comparaison purposes.
 */
class EulerIntegrator : public ExplicitIntegrator
{
public:
    //! Constructor.
    /*!
     Take the ODE to integrate and the step lenght as arguemnts.
     */
    EulerIntegrator(double (*ODE_)(double,double), double dx_);
    
    //! Integrating function.
    /*!
     Perform a step of lenght dx starting from xn and yn, calculating y(n+1) that obviosuly corresponds to xn+dx.
     */
    double step(double xn, double yn);
};

#endif