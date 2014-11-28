#include "../ExplicitIntegrators/EulerIntegrator.h"
#include "../ExplicitIntegrators/RungeKutta2.h"
#include "../ExplicitIntegrators/RungeKutta4.h"
#include "../Solvers/AnalyticalExplicitSolver.h"

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
    
    AnalyticalExplicitSolver ES(y0,xmin,xmax, new EulerIntegrator(f,dx),s);
    AnalyticalExplicitSolver RK4S(y0,xmin,xmax, new RungeKutta4(f,dx),s);
    AnalyticalExplicitSolver RK2S(y0,xmin,xmax, new RungeKutta2(f,dx),s);
    
    ES.solve();
    RK2S.solve();
    RK4S.solve();
    
    if (ES.is_solved())
    {
        print_solution( ES.get_solution(), ES.get_analytical_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
    if (RK2S.is_solved())
    {
        print_solution( RK2S.get_solution(), RK2S.get_analytical_solution());
    }
    std::cout << "\n\n"; // Start a new dataset for gnuplot
    if (RK4S.is_solved())
    {
        print_solution( RK4S.get_solution(), RK4S.get_analytical_solution());
    }
    
    
    return 0;
}