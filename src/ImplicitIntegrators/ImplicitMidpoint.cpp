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

ImplicitMidpoint::ImplicitMidpoint(double (*ODE_)(double, double),
                                   double dx_,
                                   double (*dODE_)(double, double))
  : ImplicitIntegrator(ODE_, dx_, dODE_), IMF(new IMFunction(this)) {}

double ImplicitMidpoint::step(double xn, double yn) {
  xnew = xn + 0.5 * dx;
  yold = yn;

  NewtonMethod NM(yold, IMF);

  return NM.solve();
}

ImplicitMidpoint::IMFunction::IMFunction(ImplicitMidpoint* IM_) : IM(IM_) {}

double ImplicitMidpoint::IMFunction::f(double yn) {
  return yn - IM->yold - IM->dx * IM->ODE(IM->xnew, 0.5 * (IM->yold + yn));
}

double ImplicitMidpoint::IMFunction::df(double yn) {
  return 1 - IM->dx * IM->dODE(IM->xnew, 0.5 * (IM->yold + yn)) * 0.5;
}

ImplicitMidpoint::~ImplicitMidpoint() {
  delete IMF;
}