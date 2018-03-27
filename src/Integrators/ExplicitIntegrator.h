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

#ifndef EXPLICITINTEGRATOR_H
#define EXPLICITINTEGRATOR_H

#include "Integrator.h"

//! ExplicitIntegrator class.
/*!
 ExplicitIntegrator class is a virtual class that compute an integration step
 (vistual function) for a given ODE (function pointer) of lenght step dx.
 */
class ExplicitIntegrator : public Integrator {
public:
  //! Constructor.
  /*!
   Take the ODE to integrate and the step lenght as arguemnts.
   */
  ExplicitIntegrator(double (*ODE_)(double, double), double dx_);

  ExplicitIntegrator(const ExplicitIntegrator&) = delete;
  ExplicitIntegrator(const ExplicitIntegrator&&) = delete;
  ExplicitIntegrator& operator=(const ExplicitIntegrator&) = delete;
};

#endif