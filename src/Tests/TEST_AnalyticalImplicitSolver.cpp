#include "../ImplicitIntegrators/ImplicitEuler.h"
#include "../ImplicitIntegrators/ImplicitMidpoint.h"
#include "../ImplicitIntegrators/ImplicitTrapezoidal.h"
#include "../Solvers/AnalyticalImplicitSolver.h"

#include "testfunction.h"

#include <iostream>
#include <vector>
#include <array>

void print_solution(std::vector<std::array<double,2>>  sol, std::vector<std::array<double,3>>  sol_a, std::ostream& out = std::cout)
{
    for (unsigned int i(0); i < sol.size(); i++)
    {
        // xn, yn, s(xn), abs(yn-s(xn)), abs((yn-s(xn))/s(xn))
        out << sol[i][0] << ' ' << sol[i][1] << ' ' << sol_a[i][0] << ' ' << sol_a[i][1] << ' ' << sol_a[i][2] << std::endl;
    }
}

int main()
{
    double y0(1);
    double xmin(0);
    double xmax(5);
    double dx(0.5);
    
    AnalyticalImplicitSolver IES(y0,xmin,xmax, new ImplicitEuler(f,dx,df),s);
    AnalyticalImplicitSolver IMS(y0,xmin,xmax, new ImplicitMidpoint(f,dx,df),s);
    AnalyticalImplicitSolver ITS(y0,xmin,xmax, new ImplicitTrapezoidal(f,dx,df),s);
    
    IES.solve();
    IMS.solve();
    ITS.solve();
    
    if (IES.is_solved())
    {
        print_solution( IES.get_solution(), IES.get_analytical_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
    if (IMS.is_solved())
    {
        print_solution( IMS.get_solution(), IMS.get_analytical_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
    if (ITS.is_solved())
    {
        print_solution( ITS.get_solution(), ITS.get_analytical_solution());
    }
    
    
    return 0;
}