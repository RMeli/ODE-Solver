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

#include "Solver.h"

#include "../Utilities/Exception.h"

Solver::Solver(double y0_,
               double xmin_,
               double xmax_,
               std::unique_ptr<Integrator> I_)
  : y0(y0_), xmin(xmin_), xmax(xmax_), I_ptr(std::move(I_)) {}

void Solver::solve() {
  double dx(I_ptr->get_dx());

  double xn(xmin);
  double yn(y0);

  // gcc4.8
  // std::array<double,2> step({0,0});

  std::array<double, 2> step;

  while (xn <= xmax) {
    // gcc4.8
    // step = {xn, yn};

    step[0] = xn;
    step[1] = yn;

    solution.push_back(step);

    yn = I_ptr->step(xn, yn);

    xn += dx;
  }
}

bool Solver::is_solved() const {
  return !solution.empty();
}

std::vector<std::array<double, 2>> Solver::get_solution() const {
  if (!is_solved()) {
    throw Unsolved(); // Throw Unsolved exception
  }

  return solution;
}

void Solver::print(std::ostream& out) const {
  for (std::array<double, 2> P : solution) {
    out << P[0] << ' ' << P[1] << std::endl;
  }
}