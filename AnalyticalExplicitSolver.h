#ifndef ANALYTICALEXPLICITSOLVER_H
#define ANALYTICALEXPLICITSOLVER_H

#include "Solver.h"

#include <vector>
#include <array>

class AnalyticalExplicitSolver : public Solver
{
public:
    AnalyticalExplicitSolver(double y0, double xmin_, double xmax_, Integrator* I_, double (*s_)(double));
    
    AnalyticalExplicitSolver(const AnalyticalExplicitSolver&) = delete;
    AnalyticalExplicitSolver& operator=(const AnalyticalExplicitSolver&) = delete;
    
    void solve();
    
    std::vector<std::array<double,3>> get_analytical_solution() const;
    
private:
    double (*s)(double);
    
    std::vector<std::array<double,3>> analytical_solution;
};

#endif