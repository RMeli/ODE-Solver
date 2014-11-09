#ifndef IMPLICITINTEGRATOR_H
#define IMPLICITINTEGRATOR_H

#include "NewtonMethod.h"

//! ImplicitIntegrator class.
/*!
 ImplicitIntegrator class is a virtual class that compute an integration step (virtual function) for a given ODE (function pointer) of lenght step dx,
 whit an implicit method. For an implicit method we have to solve a nonlinear function at each steps, therefore also the second derivative is needed.
 */
class ImplicitIntegrator
{
public:
    ImplicitIntegrator(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
    double get_dx() const;
    
    virtual double step(double xn, double yn) = 0;
    
    virtual ~ImplicitIntegrator();
    
protected:
    double (*ODE)(double,double);
    double (*dODE)(double,double);
    double dx;
    NewtonMethod NM;
    
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
    
    //! Nonlinear function representing the implicit method
    /*!
     To use an implicit method we need to solve a nonlinear problem in order to obtain the solution at the following step.
     This member function contains the nonlinear function to solve, which is specific for each method (and therefore is pure virtual at this stage).
     */
    virtual double NLF(double) const = 0;
    
    //! Derivative of the nonlinear function representing the implicit method
    /*!
     To use an implicit method we need to solve a nonlinear problem in order to obtain the solution at the following step.
     This member function contains the derivative nonlinear function to solve, which is specific for each method 
     (and therefore is pure virtual at this stage).
     */
    virtual double dNLF(double) const = 0;
    
};

#endif