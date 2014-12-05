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