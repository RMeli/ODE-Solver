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

#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <functional>

//! Integrator class.
/*!
 ExplicitIntegrator class is a virtual class where Implicit and Explicit
 Integrators derive
 */
template<typename T>
class Integrator {
public:
  //! Constructor.
  /*!
   Take the ODE to integrate and the step length as arguments.
   */
  Integrator(std::function<T(double, T)> ODE_, double dx_);

  Integrator(const Integrator<T>&) = delete;
  Integrator(const Integrator<T>&&) = delete;
  Integrator& operator=(const Integrator<T>&) = delete;

  //! Step lenght.
  /*!
   This function returns the step length.
   */
  double get_dx() const;

  //! Integrating function.
  /*!
   Perform a step of length dx starting from xn and yn, calculating y(n+1) that
   obviously corresponds to xn+dx. This function makes this class a pure virtual
   class and it is implemented at the level of derived class (that code
   effectively different integrators).

   This pure virtual function cannot be declared as a const function because
   ImplicitIntegrators need to modify some internal attributes.
   */
  virtual T step(double xn, T yn) = 0;

  //! Destructor.
  /*!
   Virtual classes needs virtual destructor in order to be destroyed properly.
   */
  virtual ~Integrator(){};

protected:
  //! ODE.
  /*!
   This function effectively define the ODE to solve. Is the function f(x,y)
   that defines the equation y'=f(x,y).
   */
  std::function<T(double, T)> ODE;

  //! Step length.
  double dx;
};

template<typename T>
Integrator<T>::Integrator(std::function<T(double, T)> ODE_, double dx_)
  : ODE(ODE_), dx(dx_) {}

template<typename T>
double Integrator<T>::get_dx() const {
  return dx;
}

#endif