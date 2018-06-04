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

#include "../Utilities/Exception.h"

#include <array>
#include <memory>
#include <vector>
#include <functional>
#include <cmath>

template <typename T>
class AnalyticalSolver : public Solver<T> {
public:
  //! Constructor.
  /*!
   Take the initial value y0=y(xmin), the interval of integration and an
   Integrator and the analytical solution.
   */
  AnalyticalSolver(T y0,
                   double xmin_,
                   double xmax_,
                   std::unique_ptr<Integrator<T>> I_,
                   std::function<T(double)> s_);

  AnalyticalSolver(const AnalyticalSolver<T>&) = delete;
  AnalyticalSolver(const AnalyticalSolver<T>&&) = delete;
  AnalyticalSolver& operator=(const AnalyticalSolver<T>&) = delete;

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
  std::vector<std::tuple<T, T, T>> get_analytical_solution() const;

private:
  using Solver<T>::solution;
  using Solver<T>::y0;
  using Solver<T>::I_ptr;
  using Solver<T>::xmin;
  using Solver<T>::xmax;
  
  //! Analytical solution.
  /*!
   Analytical solution (has to be provided).
   */
  std::function<T(double)> s;

  //! Analytical solution.
  /*!
   This member contains the analytical solution evaluated at the same points of
   numerical evaluation and contains also absolute and relative error.
   */
  std::vector<std::tuple<T,T,T>> analytical_solution;
};

template <typename T>
AnalyticalSolver<T>::AnalyticalSolver(T y0_,
                                   double xmin_,
                                   double xmax_,
                                   std::unique_ptr<Integrator<T>> I_,
                                   std::function<T(double)> s_)
    : Solver<T>(y0_, xmin_, xmax_, std::move(I_)), s(s_) {}
    
template <typename T>
void AnalyticalSolver<T>::solve() {
  double dx(I_ptr->get_dx());
  
  double xn(xmin);
  T yn(y0);
  
  // gcc4.8
  // std::array<double,2> step({0,0});
  // std::array<double,3> step_a({0,0,0});
  
  std::pair<double, T> step;
  std::tuple<T, T, T> step_a;
  
  while (xn <= xmax) {
    // gcc4.8
    // step = {xn, yn};
    // step_a ={s(xn), std::abs(yn-s(xn)), std::abs( (yn-s(xn))/s(xn) )};
    
    step = std::make_pair(xn, yn);
    step_a = std::make_tuple(s(xn), std::abs(yn - s(xn)), std::abs((yn - s(xn)) / s(xn)));
    
    solution.push_back(step);
    analytical_solution.push_back(step_a);
    
    yn = I_ptr->step(xn, yn);
    
    xn += dx;
  }
}

template<typename T>
std::vector<std::tuple<T,T,T>>
AnalyticalSolver<T>::get_analytical_solution() const {
  if (!Solver<T>::is_solved()) // If solution is not solved, analytical_solution is empty
    // too
  {
    throw Unsolved(); // Throw Unsolved exception
  }
  
  return analytical_solution;
}

#endif