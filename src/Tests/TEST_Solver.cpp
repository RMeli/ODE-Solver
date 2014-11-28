#include "../ExplicitIntegrators/EulerIntegrator.h"
#include "../ExplicitIntegrators/RungeKutta2.h"
#include "../ExplicitIntegrators/RungeKutta4.h"
#include "../ImplicitIntegrators/ImplicitEuler.h"
#include "../ImplicitIntegrators/ImplicitMidpoint.h"
#include "../ImplicitIntegrators/ImplicitTrapezoidal.h"
#include "../Solvers/Solver.h"

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
    
    Solver ES(y0,xmin,xmax, new EulerIntegrator(f,dx) );
    Solver RK4S(y0,xmin,xmax, new RungeKutta4(f,dx) );
    Solver RK2S(y0,xmin,xmax, new RungeKutta2(f,dx) );
    
    ES.solve();
    RK2S.solve();
    RK4S.solve();
    
    Solver IES(y0,xmin,xmax, new ImplicitEuler(f,dx,df) );
    Solver IMS(y0,xmin,xmax, new ImplicitMidpoint(f,dx,df) );
    Solver ITS(y0,xmin,xmax, new ImplicitTrapezoidal(f,dx,df) );
    
    IES.solve();
    IMS.solve();
    ITS.solve();
    
    if (ES.is_solved())
    {
        print_solution( ES.get_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
    if (RK2S.is_solved())
    {
        print_solution( RK2S.get_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
    if (RK4S.is_solved())
    {
        print_solution( RK4S.get_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
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