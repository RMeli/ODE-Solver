#ifndef INTEGRATOR_H
#define INTEGRATOR_H

//! Integrator class.
/*!
 Integrator class is a virtual class that compute an integration step (vistual function) for a given ODE (function pointer) of lenght step dx.
 */
class Integrator
{
public:
    Integrator(double (*ODE_)(double,double), double dx_);
    
    double get_dx() const;
    
    virtual double step(double xn, double yn) const = 0;
    
    virtual ~Integrator();
    
protected:
    double (*ODE)(double,double);
    double dx;
};

#endif