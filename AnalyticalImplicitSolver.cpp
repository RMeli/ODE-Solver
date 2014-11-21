#include "AnalyticalImplicitSolver.h"

#include "Exception.h"

#include <cmath>

AnalyticalImplicitSolver::AnalyticalImplicitSolver(double y0_, double xmin_, double xmax_, ImplicitIntegrator* I_, double (*s_)(double))
: ImplicitSolver(y0_,xmin_,xmax_,I_), s(s_)
{}

void AnalyticalImplicitSolver::solve()
{
    double dx( I_ptr->get_dx() );
    
    double xn(xmin);
    double yn(y0);
    
    std::array<double,2> step({0,0});
    std::array<double,3> step_a({0,0,0});
    
    while (xn < xmax)
    {
        step = {xn, yn};
        step_a ={s(xn), std::abs(yn-s(xn)), std::abs( (yn-s(xn))/s(xn) )};
        solution.push_back(step);
        analytical_solution.push_back(step_a);
        
        yn = I_ptr->step(xn,yn);
        
        xn += dx;
    }
}

std::vector<std::array<double,3>> AnalyticalImplicitSolver::get_analytical_solution() const
{
    if (!is_solved()) // If solution is not solved, analytical_solution is empty too
    {
        throw Unsolved(); // Throw Unsolved exception
    }
    
    return analytical_solution;
}