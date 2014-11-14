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
    ImplicitIntegrator(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
    double get_dx() const;
    
    virtual double step(double xn, double yn) = 0;
    
    virtual ~ImplicitIntegrator();
    
protected:
    double (*ODE)(double,double);
    double (*dODE)(double,double);
    
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