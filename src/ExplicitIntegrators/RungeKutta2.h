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

#ifndef RUNGEKUTTA2_H
#define RUNGEKUTTA2_H

#include "../Integrators/ExplicitIntegrator.h"

//! RungeKutta2 class.
/*!
 Perform one step of the explicit Runge Kutta method of order 2.
 */
template <typename T>
class RungeKutta2 : public ExplicitIntegrator<T> {
public:
  //! Constructor.
  /*!
   Take the ODE to integrate and the step lenght as arguemnts.
   */
  RungeKutta2(std::function<T(double, T)> ODE_, double dx_);

  RungeKutta2(const RungeKutta2<T>&) = delete;
  RungeKutta2(const RungeKutta2<T>&&) = delete;
  RungeKutta2& operator=(const RungeKutta2<T>&) = delete;

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

template<typename T>
RungeKutta2<T>::RungeKutta2(std::function<T(double, T)> ODE_, double dx_)
    : ExplicitIntegrator<T>(ODE_, dx_) {}
    
template<typename T>
T RungeKutta2<T>::step(double xn, T yn) {
  T k1(ODE(xn, yn));
  T k2(ODE(xn + dx, yn + dx * k1));
  
  return yn + dx / 2. * (k1 + k2);
}

#endif