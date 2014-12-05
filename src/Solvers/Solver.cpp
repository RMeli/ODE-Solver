#include "Solver.h"

#include "../Utilities/Exception.h"

Solver::Solver(double y0_, double xmin_, double xmax_, Integrator* I_)
: y0(y0_), xmin(xmin_), xmax(xmax_), I_ptr(I_)
{}

void Solver::solve()
{
    double dx( I_ptr->get_dx() );
    
    double xn(xmin);
    double yn(y0);
    
    std::array<double,2> step({0,0});
    
    while (xn <= xmax)
    {
        step = {xn, yn};
        solution.push_back(step);
        
        yn = I_ptr->step(xn,yn);
        
        xn += dx;
    }
}

bool Solver::is_solved() const
{
    return ! solution.empty();
}

std::vector<std::array<double,2>> Solver::get_solution() const
{
    if (!is_solved())
    {
        throw Unsolved(); // Throw Unsolved exception
    }
    
    return solution;
}

void Solver::print(std::ostream& out) const
{
    for (std::array<double,2> P : solution)
    {
        out << P[0] << ' ' << P[1] << std::endl;
    }
}

Solver::~Solver()
{
    delete I_ptr;
}