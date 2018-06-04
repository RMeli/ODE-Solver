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

#ifndef RUNGEKUTTA4_H
#define RUNGEKUTTA4_H

#include "../Integrators/ExplicitIntegrator.h"

//! RungeKutta4 class.
/*!
 Perform one step of the explicit Runge Kutta method of order 4.
 */
template <typename T>
class RungeKutta4 : public ExplicitIntegrator<T> {
public:
  //! Constructor.
  /*!
   Take the ODE to integrate and the step lenght as arguemnts.
   */
  RungeKutta4(std::function<T(double, T)> ODE_, double dx_);

  RungeKutta4(const RungeKutta4<T>&) = delete;
  RungeKutta4(const RungeKutta4<T>&&) = delete;
  RungeKutta4& operator=(const RungeKutta4<T>&) = delete;

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
RungeKutta4<T>::RungeKutta4(std::function<T(double, T)> ODE_, double dx_)
    : ExplicitIntegrator<T>(ODE_, dx_) {}
    
template<typename T>
T RungeKutta4<T>::step(double xn, T yn) {
  double dx2(dx / 2.);
  
  T k1(ODE(xn, yn));
  T k2(ODE(xn + dx2, yn + dx2 * k1));
  T k3(ODE(xn + dx2, yn + dx2 * k2));
  T k4(ODE(xn + dx, yn + dx * k3));
  
  return yn + dx / 6. * (k1 + 2 * k2 + 2 * k3 + k4);
}

#endif