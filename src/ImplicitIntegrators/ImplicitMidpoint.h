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

#ifndef IMPLICITMIDPOINT_H
#define IMPLICITMIDPOINT_H

#include "../Integrators/ImplicitIntegrator.h"

#include "../NumericalMethods/NewtonMethod.h"


#include <functional>

//! ImplicitMidpoint class.
/*!
 Perform one step of the implicit midpoint method.
 */
template <typename T>
class ImplicitMidpoint : public ImplicitIntegrator<T> {
public:
  //! Constructor.
  /*!
   Take the ODE to integrate, its derivative and the step lenght as arguemnts.
   */
  ImplicitMidpoint(std::function<T(double, T)> ODE_,
                   double dx_,
                   std::function<T(double, T)> dODE_);

  ImplicitMidpoint(const ImplicitMidpoint<T>&) = delete;
  ImplicitMidpoint(const ImplicitMidpoint<T>&&) = delete;
  ImplicitMidpoint& operator=(const ImplicitMidpoint<T>&) = delete;

  //! Integrating function.
  /*!
   Perform a step of lenght dx starting from xn and yn, calculating y(n+1) that
   obviosuly corresponds to xn+dx.
   */
  T step(double xn, T yn);
 
 private:
  using Integrator<T>::ODE;
  using Integrator<T>::dx;
  using ImplicitIntegrator<T>::dODE;
  using ImplicitIntegrator<T>::xnew;
  using ImplicitIntegrator<T>::yold;
};


template <typename T>
ImplicitMidpoint<T>::ImplicitMidpoint(std::function<T(double, T)> ODE_,
                                   double dx_,
                                   std::function<T(double, T)> dODE_)
    : ImplicitIntegrator<T>(ODE_, dx_, dODE_) {}
    
template <typename T>
T ImplicitMidpoint<T>::step(double xn, T yn) {
  xnew = xn + 0.5 * dx;
  yold = yn;
  
  NewtonMethod<T> NM(yold,
                          [this](T yn) {
                            return yn - yold - dx * ODE(xnew, 0.5 * (yold + yn));
                          },
                          [this](T yn) {
                            return 1 - dx * dODE(xnew, 0.5 * (yold + yn)) * 0.5;
                          });
  
  return NM.solve();
}

#endif