#include "EulerIntegrator.h"
#include "RungeKutta2.h"
#include "RungeKutta4.h"
#include "Solver.h"

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
    double xmax(5);
    double dx(0.5);
    
    Solver ES(y0,xmin,xmax, new EulerIntegrator(f,dx) );
    Solver RK4S(y0,xmin,xmax, new RungeKutta4(f,dx) );
    Solver RK2S(y0,xmin,xmax, new RungeKutta2(f,dx) );
    
    ES.solve();
    RK2S.solve();
    RK4S.solve();
    
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

    
    return 0;
}