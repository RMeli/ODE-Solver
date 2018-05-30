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
#include "../Solvers/Solver.h"

#include "testfunction.h"

#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

void print_solution(std::vector<std::array<double, 2>> sol,
                    std::ostream& out = std::cout) {
  for (std::array<double, 2> P : sol) {
    out << P[0] << ' ' << P[1] << std::endl;
  }
}

int main() {
  double y0(1);
  double xmin(0);
  double xmax(5);
  double dx(0.5);

  Solver ES(y0, xmin, xmax, std::make_unique<EulerIntegrator>(f, dx));
  Solver RK4S(y0, xmin, xmax, std::make_unique<RungeKutta4>(f, dx));
  Solver RK2S(y0, xmin, xmax, std::make_unique<RungeKutta2>(f, dx));

  ES.solve();
  RK2S.solve();
  RK4S.solve();

  Solver IES(y0, xmin, xmax, std::make_unique<ImplicitEuler>(f, dx, df));
  Solver IMS(y0, xmin, xmax, std::make_unique<ImplicitMidpoint>(f, dx, df));
  Solver ITS(y0, xmin, xmax, std::make_unique<ImplicitTrapezoidal>(f, dx, df));

  IES.solve();
  IMS.solve();
  ITS.solve();

  std::ofstream fout("output.dat");

  if (ES.is_solved()) {
    print_solution(ES.get_solution());
    ES.print(fout);
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  fout << "\n\n";
  if (RK2S.is_solved()) {
    print_solution(RK2S.get_solution());
    RK2S.print(fout);
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  fout << "\n\n";
  if (RK4S.is_solved()) {
    print_solution(RK4S.get_solution());
    RK4S.print(fout);
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  fout << "\n\n";

  if (IES.is_solved()) {
    print_solution(IES.get_solution());
    IES.print(fout);
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  fout << "\n\n";
  if (IMS.is_solved()) {
    print_solution(IMS.get_solution());
    IMS.print(fout);
  }
  std::cout << "\n\n"; // Start a new dataset for gnuplot
  fout << "\n\n";
  if (ITS.is_solved()) {
    print_solution(ITS.get_solution());
    ITS.print(fout);
  }

  fout.close();

  return 0;
}