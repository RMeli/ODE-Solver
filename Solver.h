#ifndef SOLVER_H
#define SOLVER_H

#include "Integrator.h"

#include <vector>
#include <array>

class Solver
{
public:
    Solver(double y0, double xmin_, double xmax_, Integrator* I_);
    
    Solver(const Solver&) = delete;
    Solver& operator=(const Solver&) = delete;
    
    //! Check if the problem has been solved.
    /*!
     Check if the problem has been solved by checking if the solution container is empty or not.
     */
    bool is_solved() const;
    
    void solve();
    
    std::vector<std::array<double,2>> get_solution() const;
    
    ~Solver();
    
private:
    std::vector<std::array<double,2>> solution;
    double y0;
    double xmin;
    double xmax;
    Integrator* I_ptr;
};

#endif