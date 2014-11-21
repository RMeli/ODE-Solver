#ifndef IMPLICITINTEGRATOR_H
#define IMPLICITINTEGRATOR_H

//! ImplicitIntegrator class.
/*!
 ImplicitIntegrator class is a virtual class that compute an integration step (virtual function) for a given ODE (function pointer) of lenght step dx,
 whit an implicit method. For an implicit method we have to solve a nonlinear function at each steps, therefore also the second derivative is needed.
 */
class ImplicitIntegrator
{
public:
    //! Constructor.
    /*!
     Take the ODE to integrate, its derivative and the step lenght as arguemnts.
     */
    ImplicitIntegrator(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
    //! Step lenght.
    /*!
     This function returns the step lenght.
     */
    double get_dx() const;
    
    //! Integrating function.
    /*!
     Perform a step of lenght dx starting from xn and yn, calculating y(n+1) that obviosuly corresponds to xn+dx. This function makes this class a pure virtual class and it is implemented at the level of derived class (that code effectively different integrators).
     */
    virtual double step(double xn, double yn) = 0;
    
    //! Destructor.
    /*!
     Virtual classes needs virtual destructor in order to be destroied properly.
     */
    virtual ~ImplicitIntegrator();
    
protected:
    //! ODE.
    /*!
     This function effectively define the ODE to solve. Is the function f(x,y) that defines the equation y'=f(x,y).
     */
    double (*ODE)(double,double);
    
    //! Derivative of the ODE.
    /*!
     This function is the derivative of f(x,y) with respect to y. It is needed by an implicit method that use NewtonMethod class to solve the nonlinear function defining the scheme.
     */
    double (*dODE)(double,double);
    
    //! Step lenght.
    double dx;
    
    //! xnew = xold + dx.
    /*!
     xnew is needed because must be accessible inside NLF and dNLF, on order to perform the NewtonMethod to solve the step with a one-variable function.
     */
    double xnew = 0;
    //! yold
    /*!
     xold is needed because must be accessible inside NLF and dNLF, on order to perform the NewtonMethod to solve the step with a one-variable function.
     */
    double yold = 0;
};

#endif