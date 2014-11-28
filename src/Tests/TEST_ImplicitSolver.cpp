#include "../ImplicitIntegrators/ImplicitEuler.h"
#include "../ImplicitIntegrators/ImplicitMidpoint.h"
#include "../ImplicitIntegrators/ImplicitTrapezoidal.h"
#include "../Solvers/ImplicitSolver.h"

#include "testfunction.h"

#include <iostream>
#include <vector>
#include <array>

void print_solution(std::vector<std::array<double,2>>  sol, std::ostream& out = std::cout)
{
    for (std::array<double,2> P : sol)
    {
        out << P[0] << ' ' << P[1] << std::endl;
    }
}

int main()
{
    double y0(1);
    double xmin(0);
    double xmax(30);
    double dx(0.05);
    
    ImplicitSolver IES(y0,xmin,xmax, new ImplicitEuler(f,dx,df) );
    ImplicitSolver IMS(y0,xmin,xmax, new ImplicitMidpoint(f,dx,df) );
    ImplicitSolver ITS(y0,xmin,xmax, new ImplicitTrapezoidal(f,dx,df) );
    
    IES.solve();
    IMS.solve();
    ITS.solve();
    
    if (IES.is_solved())
    {
        print_solution( IES.get_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
    if (IMS.is_solved())
    {
        print_solution( IMS.get_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
    if (ITS.is_solved())
    {
        print_solution( ITS.get_solution());
    }
    
    return 0;
}