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

#include <functional>

//! ImplicitTrapezoidal class.
/*!
 Perform one step of the implicit trapezoidal method.

 This method is of oreder two in dx (step size) and present a particularly nice
 stability region.
 */
class ImplicitTrapezoidal : public ImplicitIntegrator {
public:
  //! Constructor.
  /*!
   Take the ODE to integrate, its derivative and the step lenght as arguemnts.

   The constructor also create an instance of the ITFunction class, by using the
   this pointer to generate a link between the ITFunction class and himself.
   */
  ImplicitTrapezoidal(std::function<double(double, double)> ODE_,
                      double dx_,
                      std::function<double(double, double)> dODE_);

  ImplicitTrapezoidal(const ImplicitTrapezoidal&) = delete;
  ImplicitTrapezoidal(const ImplicitTrapezoidal&&) = delete;
  ImplicitTrapezoidal& operator=(const ImplicitTrapezoidal&) = delete;

  //! Integrating function.
  /*!
   Performs a step of lenght dx starting from xn and yn, calculating y(n+1) that
   obviosuly corresponds to xn+dx.
   */
  double step(double xn, double yn);
};

#endif