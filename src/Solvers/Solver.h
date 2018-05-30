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

#ifndef SOLVER_H
#define SOLVER_H

#include "../Integrators/Integrator.h"

#include <array>
#include <iostream>
#include <memory>
#include <vector>

class Solver {
public:
  //! Constructor.
  /*!
   Take the initial value y0=y(xmin), the interval of integration and an
   Integrator.
   */
  Solver(double y0, double xmin_, double xmax_, std::unique_ptr<Integrator> I_);

  Solver(const Solver&) = delete;
  Solver(const Solver&&) = delete;
  Solver& operator=(const Solver&) = delete;

  //! Check if the problem has been solved.
  /*!
   Check if the problem has been solved by checking if the solution container is
   empty or not.
   */
  bool is_solved() const;

  //! Solver function.
  /*!
   Use the Integrator to solve the problem, i.e. apply the integrator on the
   interval [xmin,xmax] and save the solution as points (xn,yn)
   */
  void solve();

  //! Get solution.
  /*!
   Return the solution as a vector of bi dimensional arrays. Each array contains
   the points (xn,yn)
   */
  std::vector<std::array<double, 2>> get_solution() const;

  //! Get solution.
  /*!
   Print the solution as (xn,yn) inside a given ostream: this can be the cout as
   well as a data file.
   */
  void print(std::ostream& out = std::cout) const;

protected:
  //! Solution.
  /*!
   Solution stored as a vector of bi-dimansional array corresponding to the
   points (xn,yn)
   */
  std::vector<std::array<double, 2>> solution;

  //! Initial condition.
  /*!
   Initial condition of the ODE: y0=y(xmin)
   */
  double y0;

  //! x min
  /*!
   Lower bound of the integration interval.
   */
  double xmin;

  //! x max
  /*!
   Upper bound of the integration interval.
   */
  double xmax;

  //! Integrator
  /*!
   Integrator. The solver applay this integrator starting from the given initial
   condition on the interval [xmin,xmax].
   */
  std::unique_ptr<Integrator> I_ptr;
};

#endif
