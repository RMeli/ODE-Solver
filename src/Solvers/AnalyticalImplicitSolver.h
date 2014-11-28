#ifndef ANALYTICALIMPLICITSOLVER_H
#define ANALYTICALIMPLICITSOLVER_H

#include "ImplicitSolver.h"

#include <vector>
#include <array>

class AnalyticalImplicitSolver : public ImplicitSolver
{
public:
    AnalyticalImplicitSolver(double y0, double xmin_, double xmax_, ImplicitIntegrator* I_, double (*s_)(double));
    
    AnalyticalImplicitSolver(const AnalyticalImplicitSolver&) = delete;
    AnalyticalImplicitSolver& operator=(const AnalyticalImplicitSolver&) = delete;
    
    void solve();
    
    std::vector<std::array<double,3>> get_analytical_solution() const;
    
private:
    double (*s)(double);
    
    std::vector<std::array<double,3>> analytical_solution;
};

#endif