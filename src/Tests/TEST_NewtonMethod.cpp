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
#include "../Utilities/Function.h"

#include <iostream>

class MyFunction1 : public Function
{
public:
    double f(double y)
    {
        return y*y - 2;
    }
    
    double df(double y)
    {
        return 2*y;
    }
};

class MyFunction2 : public Function
{
public:
    double f(double y)
    {
        return y*y - 3;
    }
    double df(double y)
    {
        return 2*y;
    }
};

int main()
{
    double y0(1);
    
    MyFunction1* F1(new MyFunction1);
    MyFunction2* F2(new MyFunction2);
    
    NewtonMethod NM(y0,F1);
    
    std::cout << NM.solve() << std::endl;
    
    // Change the function to solve
    NM.set(y0,F2);
    
    std::cout << NM.solve() << std::endl;
    
    return 0;
}