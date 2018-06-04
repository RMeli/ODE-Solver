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
 Perform one step of the explicite Euler method, probably the simplest method to
 solve ODEs.

 This method is of oreder one in dx (step size) and present problems of
 stability. This method should be used with small step size (pay attention to
 rounding errors) and only for comparaison purposes.
 */
template <typename T>
class EulerIntegrator : public ExplicitIntegrator<T> {
public:
  //! Constructor.
  /*!
   Take the ODE to integrate and the step lenght as arguemnts.
   */
  EulerIntegrator(std::function<T(double, T)> ODE_, double dx_);

  EulerIntegrator(const EulerIntegrator<T>&) = delete;
  EulerIntegrator(const EulerIntegrator<T>&&) = delete;
  EulerIntegrator& operator=(const EulerIntegrator<T>&) = delete;

  //! Integrating function.
  /*!
   Perform a step of lenght dx starting from xn and yn, calculating y(n+1) that
   obviosuly corresponds to xn+dx.
   */
  T step(double xn, T yn);
  
  private:
  using Integrator<T>::ODE;
  using Integrator<T>::dx;
};

template <typename T>
EulerIntegrator<T>::EulerIntegrator(std::function<T(double, T)> ODE_,
                                 double dx_)
    : ExplicitIntegrator<T>(ODE_, dx_) {}

template <typename T>
T EulerIntegrator<T>::step(double xn, T yn) {
  return yn + dx * ODE(xn, yn);
}

#endif