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

#include "../ImplicitIntegrators/ImplicitEuler.h"
#include "testfunction.h"

#include <iostream>

int main() {
  double xmax(5);

  double dx(0.5);
  double xn(0);
  double yn(1);

  ImplicitEuler<double> IE(f, dx, df);

  while (xn < xmax) {
    std::cout << xn << ' ' << yn << std::endl;

    yn = IE.step(xn, yn);
    xn += dx;
  }

  return 0;
}