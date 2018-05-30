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

#include "../NumericalMethods/NewtonMethod.h"

#include <iostream>

int main() {
  double y0(1);

  NewtonMethod<double> NM(
      y0, [](double y) { return y * y - 2; }, [](double y) { return 2 * y; });

  std::cout << NM.solve() << std::endl;

  // Change the function to solve
  NM.set(
      y0, [](double y) { return y * y - 3; }, [](double y) { return 2 * y; });

  std::cout << NM.solve() << std::endl;

  return 0;
}