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


#include "RungeKutta4.h"

RungeKutta4::RungeKutta4(double (*ODE_)(double,double), double dx_)
: ExplicitIntegrator(ODE_,dx_)
{}

double RungeKutta4::step(double xn, double yn)
{
    double dx2(dx/2.);
    
    double k1( ODE(xn,yn) );
    double k2( ODE(xn + dx2, yn + dx2 * k1) );
    double k3( ODE(xn + dx2, yn + dx2 * k2) );
    double k4( ODE(xn  + dx, yn + dx * k3) );
    
    return yn + dx/6. * (k1 + 2*k2 + 2*k3 + k4);
}