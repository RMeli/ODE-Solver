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

#include "NewtonMethod.h"

#include "../Utilities/Exception.h"

#include <cmath>
#include <stdexcept>

NewtonMethod::NewtonMethod(double y0_,
                           std::function<double(double)> f_,
                           std::function<double(double)> df_,
                           double tol_,
                           int maxiter_)
  : y0(y0_), f(f_), df(df_), tol(tol_), maxiter(maxiter_) {}

double NewtonMethod::solve() const {
  double yold(y0);
  double ynew(y0);

  double derivative(0);

  double iter(0);

  do {
    if (iter > maxiter) {
      throw std::overflow_error(
          "Maximum iterations reached. Convergence not reached.");
    }

    yold = ynew;

    derivative = df(yold);

    if (std::abs(derivative) < 1e-30) {
      throw std::overflow_error("Divide by zero exception.");
    }

    ynew = yold - f(yold) / derivative;

    iter++;

  } while (std::abs(ynew - yold) > tol);

  return ynew;
}

void NewtonMethod::set(double y0_,
                       std::function<double(double)> f_,
                       std::function<double(double)> df_,
                       double tol_,
                       int maxiter_) {
  y0 = y0_;
  f = f_;
  df = df_;
  tol = tol_;
  maxiter = maxiter_;
}