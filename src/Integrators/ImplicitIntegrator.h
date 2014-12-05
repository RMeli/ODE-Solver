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


#ifndef IMPLICITINTEGRATOR_H
#define IMPLICITINTEGRATOR_H

#include "Integrator.h"

//! ImplicitIntegrator class.
/*!
 ImplicitIntegrator class is a virtual class that compute an integration step (virtual function) for a given ODE (function pointer) of lenght step dx,
 whit an implicit method. For an implicit method we have to solve a nonlinear function at each steps, therefore also the second derivative is needed.
 */
class ImplicitIntegrator : public Integrator
{
public:
    //! Constructor.
    /*!
     Take the ODE to integrate, its derivative and the step lenght as arguemnts.
     */
    ImplicitIntegrator(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
protected:
    //! Derivative of the ODE.
    /*!
     This function is the derivative of f(x,y) with respect to y. It is needed by an implicit method that use NewtonMethod class to solve the nonlinear function defining the scheme.
     */
    double (*dODE)(double,double);
    
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