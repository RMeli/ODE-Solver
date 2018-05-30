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

#ifndef ANALYTICALSOLVER_H
#define ANALYTICALSOLVER_H

#include "Solver.h"

#include <array>
#include <memory>
#include <vector>

class AnalyticalSolver : public Solver {
public:
  //! Constructor.
  /*!
   Take the initial value y0=y(xmin), the interval of integration and an
   Integrator and the analytical solution.
   */
  AnalyticalSolver(double y0,
                   double xmin_,
                   double xmax_,
                   std::unique_ptr<Integrator> I_,
                   double (*s_)(double));

  AnalyticalSolver(const AnalyticalSolver&) = delete;
  AnalyticalSolver(const AnalyticalSolver&&) = delete;
  AnalyticalSolver& operator=(const AnalyticalSolver&) = delete;

  //! Solve.
  /*!
   Solve the problem and also evaluate the analytical solution at the same
   points of numerical evaluation.
   */
  void solve();

  //! Return analytical solution.
  /*!
   This function return the analytical_solution member. This member contains the
   analytical solution evaluated at the same points of numerical evaluation and
   contains also absolute and relative error.
   */
  std::vector<std::array<double, 3>> get_analytical_solution() const;

private:
  //! Analytical solution.
  /*!
   Pointer to the analytical solution (has to be provided).
   */
  double (*s)(double);

  //! Analytical solution.
  /*!
   This member contains the analytical solution evaluated at the same points of
   numerical evaluation and contains also absolute and relative error.
   */
  std::vector<std::array<double, 3>> analytical_solution;
};

#endif