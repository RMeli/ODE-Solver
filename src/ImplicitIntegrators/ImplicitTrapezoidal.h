/*
 This file is part of the ODEs program.
 
 Copyright (C) 2014 Rocco Meli (rocco.meli@epfl.ch)
 
 ODEs program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef IMPLICITTRAPEZOIDAL_H
#define IMPLICITTRAPEZOIDAL_H

#include "../Integrators/ImplicitIntegrator.h"
#include "../Utilities/Function.h"

//! ImplicitTrapezoidal class.
/*!
 Perform one step of the implicit trapezoidal method.
 
 This method is of oreder two in dx (step size) and present a particularly nice stability region.
 */
class ImplicitTrapezoidal : public ImplicitIntegrator
{
public:
    //! Constructor.
    /*!
     Take the ODE to integrate, its derivative and the step lenght as arguemnts.
     
     The constructor also create an instance of the ITFunction class, by using the this pointer to generate a link between the ITFunction class and himself.
     */
    ImplicitTrapezoidal(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
    //! Integrating function.
    /*!
     Performs a step of lenght dx starting from xn and yn, calculating y(n+1) that obviosuly corresponds to xn+dx.
     */
    double step(double xn, double yn);
    
    //! Destructor.
    /*!
     Needed an explicit definition of the destructor, in order to delete the pointer to ITFunction class.
     */
    ~ImplicitTrapezoidal();
    
private:
    //! ITFunction class.
    /*!
     This class, which derive from the pure virtual class Function, defines the nonlinear equation (and its derivative) to solve in order to perform an integration step. This is needed by the NewtonMethod class used in the step function.
     
     This class is defined as a nasted class of the ImplicitTrapezoidal integrator in oder to keep private the nonlinear function to solve, while using a general NewtonMethod class that works on any Function (this is needed because a pointer to a function is different from a pointer to a member function). A class defined as nasted class is automatically a friend class of the container class (ImplicitEuler in this case) and therefore we can access directly the private members of the containign class. This is useful as the nonlinear function needs private members of ImplicitTrapezoidal (a pointer to the ImplicitIntegrator is stored inside the ITFunction class).
     */
    class ITFunction : public Function
    {
    public:
        //! Constructor.
        /*!
         Take a pointer to an ImplicitTrapezoidal integrator. This link is needed because the functions f and df that define implicit method needs private members of the ImplicitIntegrator class.
         */
        ITFunction(ImplicitTrapezoidal*);
        
        //! Nonlinear function.
        /*!
         Nonlinear function defining the implicit trapezoidal method
         */
        double f(double);
        
        //! Nonlinear function's derivative.
        /*!
         Derivative of the nonlinear function defining the implicit trapezoidal method (needed by NewtonMethod)
         */
        double df(double);
        
    private:
        //! Pointer to an ImplicitTrapezoidal (friend class) integrator.
        /*!
         This pointer is used in f and df as this functions needs private members of the ImplicitTrapezoidal.
         
         No destructor needed because ImplcitiTrapezoidal destruction is handled by the ImplicitSolver.
         */
        ImplicitTrapezoidal* IT;
    };
    
    //! Pointer to ITFunction.
    /*!
     The ITFunction class is defined here as a nasted class. However, obviously, an instance of the class is needed and this pointer is used to store an IEFunction object: we have a double link between ITFunction and ImplicitTrapezoidal integrator (each class points to the other). A the ITFunction is initialized inside the constructor of the ImplicitTrapezoidal with the this pointer, no mismatch is allowed.
     */
    ITFunction* ITF;
    
};

#endif