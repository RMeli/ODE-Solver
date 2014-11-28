#ifndef ANALYTICALSOLVER_H
#define ANALYTICALSOLVER_H

#include "Solver.h"

#include <vector>
#include <array>

class AnalyticalSolver : public Solver
{
public:
    AnalyticalSolver(double y0, double xmin_, double xmax_, Integrator* I_, double (*s_)(double));
    
    AnalyticalSolver(const AnalyticalSolver&) = delete;
    AnalyticalSolver& operator=(const AnalyticalSolver&) = delete;
    
    void solve();
    
    std::vector<std::array<double,3>> get_analytical_solution() const;
    
private:
    double (*s)(double);
    
    std::vector<std::array<double,3>> analytical_solution;
};

#endif