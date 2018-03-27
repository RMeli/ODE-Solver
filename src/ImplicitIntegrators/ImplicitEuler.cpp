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

#include "ImplicitEuler.h"
#include "../NumericalMethods/NewtonMethod.h"

ImplicitEuler::ImplicitEuler(double (*ODE_)(double, double),
                             double dx_,
                             double (*dODE_)(double, double))
  : ImplicitIntegrator(ODE_, dx_, dODE_), IEF(new IEFunction(this)) {}

double ImplicitEuler::step(double xn, double yn) {
  xnew = xn + dx;
  yold = yn;

  NewtonMethod NM(yold, IEF);

  return NM.solve();
}

ImplicitEuler::IEFunction::IEFunction(ImplicitEuler* IE_) : IE(IE_) {}

double ImplicitEuler::IEFunction::f(double yn) {
  return yn - IE->dx * IE->ODE(IE->xnew, yn) - IE->yold;
}

double ImplicitEuler::IEFunction::df(double yn) {
  return 1 - IE->dx * IE->dODE(IE->xnew, yn);
}

ImplicitEuler::~ImplicitEuler() {
  delete IEF;
}