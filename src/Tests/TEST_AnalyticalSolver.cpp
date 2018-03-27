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

#include "../ExplicitIntegrators/EulerIntegrator.h"
#include "../ExplicitIntegrators/RungeKutta2.h"
#include "../ExplicitIntegrators/RungeKutta4.h"
#include "../ImplicitIntegrators/ImplicitEuler.h"
#include "../ImplicitIntegrators/ImplicitMidpoint.h"
#include "../ImplicitIntegrators/ImplicitTrapezoidal.h"
#include "../Solvers/AnalyticalSolver.h"

#include "testfunction.h"

#include <array>
#include <iostream>
#include <vector>

void print_solution(std::vector<std::array<double, 2>> sol,
                    std::vector<std::array<double, 3>> sol_a,
                    std::ostream& out = std::cout) {
  for (unsigned int i(0); i < sol.size(); i++) {
    // xn, yn, s(xn), abs(yn-s(xn)), abs((yn-s(xn))/s(xn))
    out << sol[i][0] << ' ' << sol[i][1] << ' ' << sol_a[i][0] << ' '
        << sol_a[i][1] << ' ' << sol_a[i][2] << std::endl;
  }
}

int main() {
  double y0(1);
  double xmin(0);
  double xmax(5);
  double dx(0.5);

  AnalyticalSolver ES(y0, xmin, xmax, new EulerIntegrator(f, dx), s);
  AnalyticalSolver RK4S(y0, xmin, xmax, new RungeKutta4(f, dx), s);
  AnalyticalSolver RK2S(y0, xmin, xmax, new RungeKutta2(f, dx), s);

  ES.solve();
  RK2S.solve();
  RK4S.solve();

  AnalyticalSolver IES(y0, xmin, xmax, new ImplicitEuler(f, dx, df), s);
  AnalyticalSolver IMS(y0, xmin, xmax, new ImplicitMidpoint(f, dx, df), s);
  AnalyticalSolver ITS(y0, xmin, xmax, new ImplicitTrapezoidal(f, dx, df), s);

  IES.solve();
  IMS.solve();
  ITS.solve();

  if (ES.is_solved()) {
    print_solution(ES.get_solution(), ES.get_analytical_solution());
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  if (RK2S.is_solved()) {
    print_solution(RK2S.get_solution(), RK2S.get_analytical_solution());
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  if (RK4S.is_solved()) {
    print_solution(RK4S.get_solution(), RK4S.get_analytical_solution());
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  if (IES.is_solved()) {
    print_solution(IES.get_solution(), IES.get_analytical_solution());
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  if (IMS.is_solved()) {
    print_solution(IMS.get_solution(), IMS.get_analytical_solution());
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  if (ITS.is_solved()) {
    print_solution(ITS.get_solution(), ITS.get_analytical_solution());
  }

  return 0;
}