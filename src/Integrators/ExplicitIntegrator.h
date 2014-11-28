#ifndef EXPLICITINTEGRATOR_H
#define EXPLICITINTEGRATOR_H

#include "Integrator.h"

//! ExplicitIntegrator class.
/*!
 ExplicitIntegrator class is a virtual class that compute an integration step (vistual function) for a given ODE (function pointer) of lenght step dx.
 */
class ExplicitIntegrator : public Integrator
{
public:
    //! Constructor.
    /*!
     Take the ODE to integrate and the step lenght as arguemnts.
     */
    ExplicitIntegrator(double (*ODE_)(double,double), double dx_);
};

#endif