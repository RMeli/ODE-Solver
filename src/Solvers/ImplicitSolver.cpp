#include "ImplicitSolver.h"

#include "../Utilities/Exception.h"

ImplicitSolver::ImplicitSolver(double y0_, double xmin_, double xmax_, ImplicitIntegrator* I_)
: y0(y0_), xmin(xmin_), xmax(xmax_), I_ptr(I_)
{}

void ImplicitSolver::solve()
{
    double dx( I_ptr->get_dx() );
    
    double xn(xmin);
    double yn(y0);
    
    std::array<double,2> step({0,0});
    
    while (xn < xmax)
    {
        step = {xn, yn};
        solution.push_back(step);
        
        yn = I_ptr->step(xn,yn);
        
        xn += dx;
    }
}

bool ImplicitSolver::is_solved() const
{
    return ! solution.empty();
}

std::vector<std::array<double,2>> ImplicitSolver::get_solution() const
{
    if (!is_solved())
    {
        throw Unsolved(); // Throw Unsolved exception
    }
    
    return solution;
}

ImplicitSolver::~ImplicitSolver()
{
    delete I_ptr;
}