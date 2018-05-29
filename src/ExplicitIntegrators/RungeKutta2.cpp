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

#include "RungeKutta2.h"

RungeKutta2::RungeKutta2(std::function<double(double,double)> ODE_, double dx_)
  : ExplicitIntegrator(ODE_, dx_) {}

double RungeKutta2::step(double xn, double yn) {
  double k1(ODE(xn, yn));
  double k2(ODE(xn + dx, yn + dx * k1));

  return yn + dx / 2. * (k1 + k2);
}