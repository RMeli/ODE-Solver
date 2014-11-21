#ifndef IMPLICITEULER_H
#define IMPLICITEULER_H

#include "ImplicitIntegrator.h"
#include "Function.h"

//! ImplicitEuler class.
/*!
 Perform one step of the implicit Euler method.
 
 This method is of oreder two in dx (step size) and normally is better than the explicite Euler method concerning stability.
 */
class ImplicitEuler : public ImplicitIntegrator
{
public:
    //! Constructor.
    /*!
     Take the ODE to integrate, its derivative and the step lenght as arguemnts.
     
     The constructor also create an instance of the IEFunction class, by using the this pointer to generate a link between the IEFunction class and himself.
     */
    ImplicitEuler(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
    //! Integrating function.
    /*!
     Performs a step of lenght dx starting from xn and yn, calculating y(n+1) that obviosuly corresponds to xn+dx.
     */
    double step(double xn, double yn);
    
    //! Destructor.
    /*!
     Needed an explicit definition of the destructor, in order to delete the pointer to IEFunction class.
     */
    ~ImplicitEuler();
    
private:
    //! IEFunction class.
    /*!
     This class, which derive from the pure virtual class Function, defines the nonlinear equation (and its derivative) to solve in order to perform an integration step. This is needed by the NewtonMethod class used in the step function.
     
     This class is defined as a nasted class of the ImplicitEuler integrator in oder to keep private the nonlinear function to solve, while using a general NewtonMethod class that works on any Function (this is needed because a pointer to a function is different from a pointer to a member function). A class defined as nasted class is automatically a friend class of the container class (ImplicitEuler in this case) and therefore we can access directly the private members of the containign class. This is useful as the nonlinear function needs private members of ImplicitIntegrator (a pointer to the ImplicitIntegrator is stored inside the IEFunction class).
     */
    class IEFunction : public Function
    {
    public:
        //! Constructor.
        /*!
         Take a pointer to an ImplicitEuler integrator. This link is needed because the functions f and df that define implicit method needs private members of the ImplicitIntegrator class.
         */
        IEFunction(ImplicitEuler*);
        
        //! Nonlinear function.
        /*!
         Nonlinear function defining the implicit Euler method
         */
        double f(double);
        
        //! Nonlinear function's derivative.
        /*!
         Derivative of the nonlinear function defining the implicit Euler method (needed by NewtonMethod)
         */
        double df(double);
        
    private:
        //! Pointer to an ImplicitEuler (class friend) integrator.
        /*!
         This pointer is used in f and df as this functions needs private members of the ImplicitEuler.
         
         No destructor needed because ImplcitiEuler destruction is handled by the ImplicitSolver.
         */
        ImplicitEuler* IE;
    };
    
    //! Pointer to IEFunction.
    /*!
     The IEFunction class is defined here as a nasted class. However, obviously, an instance of the class is needed and this pointer is used to store an IEFunction object: we have a double link between IEFunction and ImplicitEuler integrator (each class points to the other). A the IEFunction is initialized inside the constructor of the ImplicitEuler with the this pointer, no mismatch is allowed.
     */
    IEFunction* IEF;
};

#endif