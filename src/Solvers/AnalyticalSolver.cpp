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

#include "AnalyticalSolver.h"

#include "../Utilities/Exception.h"

#include <cmath>

AnalyticalSolver::AnalyticalSolver(double y0_,
                                   double xmin_,
                                   double xmax_,
                                   Integrator* I_,
                                   double (*s_)(double))
  : Solver(y0_, xmin_, xmax_, I_), s(s_) {}

void AnalyticalSolver::solve() {
  double dx(I_ptr->get_dx());

  double xn(xmin);
  double yn(y0);

  // gcc4.8
  // std::array<double,2> step({0,0});
  // std::array<double,3> step_a({0,0,0});

  std::array<double, 2> step;
  std::array<double, 3> step_a;

  while (xn <= xmax) {
    // gcc4.8
    // step = {xn, yn};
    // step_a ={s(xn), std::abs(yn-s(xn)), std::abs( (yn-s(xn))/s(xn) )};

    step[0] = xn;
    step[1] = yn;

    step_a[0] = s(xn);
    step_a[1] = std::abs(yn - s(xn));
    step_a[2] = std::abs((yn - s(xn)) / s(xn));

    solution.push_back(step);
    analytical_solution.push_back(step_a);

    yn = I_ptr->step(xn, yn);

    xn += dx;
  }
}

std::vector<std::array<double, 3>>
AnalyticalSolver::get_analytical_solution() const {
  if (!is_solved()) // If solution is not solved, analytical_solution is empty
                    // too
  {
    throw Unsolved(); // Throw Unsolved exception
  }

  return analytical_solution;
}