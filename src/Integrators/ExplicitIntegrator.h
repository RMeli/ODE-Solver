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

#include <memory>

//! ExplicitIntegrator class.
/*!
 ExplicitIntegrator class is a virtual class that compute an integration step
 (vistual function) for a given ODE (function pointer) of lenght step dx.
 */
template<typename T>
class ExplicitIntegrator : public Integrator<T> {
public:
  //! Constructor.
  /*!
   Take the ODE to integrate and the step lenght as arguemnts.
   */
  ExplicitIntegrator(std::function<T(double, T)> ODE_, double dx_);

  ExplicitIntegrator(const ExplicitIntegrator<T>&) = delete;
  ExplicitIntegrator(const ExplicitIntegrator<T>&&) = delete;
  ExplicitIntegrator& operator=(const ExplicitIntegrator<T>&) = delete;
};

template<typename T>
ExplicitIntegrator<T>::ExplicitIntegrator(std::function<T(double, T)> ODE_,
                                          double dx_)
  : Integrator<T>(ODE_, dx_) {}

#endif