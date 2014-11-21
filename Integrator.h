#ifndef INTEGRATOR_H
#define INTEGRATOR_H

//! Integrator class.
/*!
 Integrator class is a virtual class that compute an integration step (vistual function) for a given ODE (function pointer) of lenght step dx.
 */
class Integrator
{
public:
    //! Constructor.
    /*!
     Take the ODE to integrate and the step lenght as arguemnts.
     */
    Integrator(double (*ODE_)(double,double), double dx_);
    
    //! Step lenght.
    /*!
     This function returns the step lenght.
     */
    double get_dx() const;
    
    //! Integrating function.
    /*!
     Perform a step of lenght dx starting from xn and yn, calculating y(n+1) that obviosuly corresponds to xn+dx. This function makes this class a pure virtual class and it is implemented at the level of derived class (that code effectively different integrators).
     */
    virtual double step(double xn, double yn) const = 0;
    
    //! Destructor.
    /*!
     Virtual classes needs virtual destructor in order to be destroied properly.
     */
    virtual ~Integrator();
    
protected:
    //! ODE.
    /*!
     This function effectively define the ODE to solve. Is the function f(x,y) that defines the equation y'=f(x,y).
     */
    double (*ODE)(double,double);
    
    //! Step lenght.
    double dx;
};

#endif