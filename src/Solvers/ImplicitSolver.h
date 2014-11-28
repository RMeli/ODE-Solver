#ifndef IMPLICITSOLVER_H
#define IMPLICITSOLVER_H

#include "../ImplicitIntegrators/ImplicitIntegrator.h"

#include <vector>
#include <array>

//! ImplicitSolver class.
/*!
 As the ImplictiIntegrator class only perform one integration steps. In order to solve the whole problem on a given interval [x0,xN] with initial condition y(x0)=y0 we need to perform many steps. The ImplicitSolver class is used to solve the whole problem with a given ImplicitIntegrator.
 */
class ImplicitSolver
{
public:
    ImplicitSolver(double y0, double xmin_, double xmax_, ImplicitIntegrator* I_);
    
    //! Deleted copy constructor.
    /*!
     As it makes little sense to copy an ImplicitSolver then copy constructor is deleted. In fact the default copy constructor is not appropriate, as the class contains a pointer.
     */
    ImplicitSolver(const ImplicitSolver&) = delete;
    
    //! Deleted assignement operator.
    /*!
     As it makes little sense to copy an ImplicitSolver then the assignement operator is deleted. In fact the default assignement operator is not appropriate, as the class contains a pointer.
     */
    ImplicitSolver& operator=(const ImplicitSolver&) = delete;
    
    //! Check if the problem has been solved.
    /*!
     Check if the problem has been solved by checking if the solution container is empty or not.
     */
    bool is_solved() const;
    
    //! Solve function.
    /*!
     This function actually solve the problem by applying many times the ImplicitIntegrator to te problem (given interval [x0,xN]) starting with the initial condition y(x0)=y0.
     */
    void solve();
    
    //! Getter for problem's solution.
    /*!
     This function returns problem's solution, i.e. an std::vector containing std::array of couples (xn,yn) that represents the solution yn at point xn.
     */
    std::vector<std::array<double,2>> get_solution() const;
    
    //! Destructor.
    /*!
     Needed an explicit definition of the constructor, in order to delete the pointer to ImplicitMethod class.
     */
    ~ImplicitSolver();
    
protected:
    //! Solution of the problem.
    /*!
     The solution of the problem is a std::vector containing std::array of couples (xn,yn) that represents the solution yn at point xn.
     */
    std::vector<std::array<double,2>> solution;
    
    //! Initial condition.
    double y0;
    
    //! xmin thet defines the initial condition y(xmin)=y0.
    double xmin;
    
    //! xmax thet defines the interval [xmin,xmax] where to solve the problem.
    double xmax;
    
    //! Pointer to ImplicitIntegrator, the integrator used to solve the problem.
    ImplicitIntegrator* I_ptr;
};

#endif