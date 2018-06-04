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

#ifndef NEWTONMETHOD_H
#define NEWTONMETHOD_H

#include <cmath>
#include <functional>
#include <stdexcept>

//! NewtonMethod class.
/*!
 NewtonMethod class solve the equation f(x) = 0, finding x0 such that f(x0) = 0
 */

template<typename T>
class NewtonMethod {
public:
  //! Constructor.
  /*!
   The constructor take the starting parameter y0 and an instance of the class
   Function (or better, an instance of a derived class of Function, as Function
   is pure virtual) that contains the function f(x) and its derivative. The
   tolerance of the iterative method and the maximum number of iterations
   (Newton converge extremely fast if the starting point is close to the
   solution, but can have a non converging or diverging behaviour if the
   starting point is not choosen wisely) are optional parameters.
   */
  NewtonMethod(T y0_,
               std::function<double(T)> f_,
               std::function<T(T)> df_,
               double tol_ = 1e-6,
               int maxiter_ = 1000);

  NewtonMethod(const NewtonMethod&) = delete;
  NewtonMethod(const NewtonMethod&&) = delete;
  NewtonMethod& operator=(const NewtonMethod&) = delete;

  //! Solver.
  /*!
   This function effectively solve the problem and return x0 such that f(x0)=0
   */
  T solve() const;

  //! Set/reset the method.
  /*!
   This function has the same arguments than the constructor and can be used to
   reset the method. This allow us to use the same instance of the Newton method
   with different functions.
   */
  void set(T y0_,
           std::function<double(T)> f,
           std::function<T(T)> df_,
           double tol_ = 1e-6,
           int maxiter_ = 1000);

private:
  //! Starting point.
  /*!
   To ensure convergence (that is normally fast) it is recomended to choose a
   starting point close to the (guessed) solution.
   */
  T y0;

  //! Function.
  /*!
   This contains the function f(x).
   */
  std::function<double(T)> f;

  //! Function derivative.
  /*!
   This contains the derivative f'(x) of the function f(x).
   */
  std::function<T(T)> df;

  //! Tolerance.
  /*!
   Exit condition of the iterative method. The iterative method stops when
   |f(x_old)-f(x_new)| < tol
   */
  double tol;

  //! Maximal number of iterations.
  /*!
   If the starting point y0 is not choosen wisely the Newton method can
   oscillate between two points or diverge. The maximal number of iterations
   avoids infinite loops.
   */
  int maxiter;
};

template<typename T>
NewtonMethod<T>::NewtonMethod(T y0_,
                              std::function<double(T)> f_,
                              std::function<T(T)> df_,
                              double tol_,
                              int maxiter_)
  : y0(y0_), f(f_), df(df_), tol(tol_), maxiter(maxiter_) {}

template<typename T>
T NewtonMethod<T>::solve() const {
  T yold(y0);
  T ynew(y0);

  T derivative(0);

  int iter(0);

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

template<typename T>
void NewtonMethod<T>::set(T y0_,
                          std::function<double(T)> f_,
                          std::function<T(T)> df_,
                          double tol_,
                          int maxiter_) {
  y0 = y0_;
  f = f_;
  df = df_;
  tol = tol_;
  maxiter = maxiter_;
}

#endif