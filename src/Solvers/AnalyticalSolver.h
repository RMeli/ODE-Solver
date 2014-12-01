#ifndef ANALYTICALSOLVER_H
#define ANALYTICALSOLVER_H

#include "Solver.h"

#include <vector>
#include <array>

class AnalyticalSolver : public Solver
{
public:
    //! Constructor.
    /*!
     Take the initial value y0=y(xmin), the interval of integration and an Integrator and the analytical solution.
     */
    AnalyticalSolver(double y0, double xmin_, double xmax_, Integrator* I_, double (*s_)(double));
    
    AnalyticalSolver(const AnalyticalSolver&) = delete;
    AnalyticalSolver(const AnalyticalSolver&&) = delete;
    AnalyticalSolver& operator=(const AnalyticalSolver&) = delete;
    
    //! Solve.
    /*!
     Solve the problem and also evaluate the analytical solution at the same points of numerical evaluation.
     */
    void solve();
    
    //! Return analytical solution.
    /*!
     This function return the analytical_solution member. This member contains the analytical solution evaluated at the same points of numerical evaluation and contains also absolute and relative error.
     */
    std::vector<std::array<double,3>> get_analytical_solution() const;
    
private:
    //! Analytical solution.
    /*!
     Pointer to the analytical solution (has to be provided).
     */
    double (*s)(double);
    
    //! Analytical solution.
    /*!
     This member contains the analytical solution evaluated at the same points of numerical evaluation and contains also absolute and relative error.
     */
    std::vector<std::array<double,3>> analytical_solution;
};

#endif