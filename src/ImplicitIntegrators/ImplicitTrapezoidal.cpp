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

#include "ImplicitTrapezoidal.h"
#include "../NumericalMethods/NewtonMethod.h"

ImplicitTrapezoidal::ImplicitTrapezoidal(
    std::function<double(double, double)> ODE_,
    double dx_,
    std::function<double(double, double)> dODE_)
  : ImplicitIntegrator(ODE_, dx_, dODE_) {}

double ImplicitTrapezoidal::step(double xn, double yn) {
  xnew = xn + dx;
  yold = yn;

  NewtonMethod<double> NM(yold,
                  [this](double yn) {
                    return yn - yold -
                           0.5 * dx * (ODE(xnew - dx, yold) + ODE(xnew, yn));
                  },
                  [this](double yn) { return 1 - 0.5 * dx * dODE(xnew, yn); });

  return NM.solve();
}