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

#include "ImplicitMidpoint.h"
#include "../NumericalMethods/NewtonMethod.h"

ImplicitMidpoint::ImplicitMidpoint(std::function<double(double, double)> ODE_,
                                   double dx_,
                                   std::function<double(double, double)> dODE_)
  : ImplicitIntegrator(ODE_, dx_, dODE_) {}

double ImplicitMidpoint::step(double xn, double yn) {
  xnew = xn + 0.5 * dx;
  yold = yn;

  NewtonMethod NM(yold,
                  [this](double yn) {
                    return yn - yold - dx * ODE(xnew, 0.5 * (yold + yn));
                  },
                  [this](double yn) {
                    return 1 - dx * dODE(xnew, 0.5 * (yold + yn)) * 0.5;
                  });

  return NM.solve();
}