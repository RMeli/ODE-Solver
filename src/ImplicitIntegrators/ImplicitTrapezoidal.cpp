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

#include "ImplicitTrapezoidal.h"
#include "../NumericalMethods/NewtonMethod.h"

ImplicitTrapezoidal::ImplicitTrapezoidal(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double))
: ImplicitIntegrator(ODE_,dx_, dODE_), ITF(new ITFunction(this))
{}

double ImplicitTrapezoidal::step(double xn, double yn)
{
    xnew = xn + dx;
    yold = yn;
    
    NewtonMethod NM(yold,ITF);
    
    return NM.solve();
}

ImplicitTrapezoidal::ITFunction::ITFunction(ImplicitTrapezoidal* IT_)
: IT(IT_)
{}

double ImplicitTrapezoidal::ITFunction::f(double yn)
{
    return yn - IT->yold - 0.5 * IT->dx * (IT->ODE(IT->xnew - IT->dx, IT->yold) + IT->ODE(IT->xnew,yn) );
}

double ImplicitTrapezoidal::ITFunction::df(double yn)
{
    return 1 - 0.5 * IT->dx * IT->dODE(IT->xnew,yn);
}

ImplicitTrapezoidal::~ImplicitTrapezoidal()
{
    delete ITF;
}