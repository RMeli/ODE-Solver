#ifndef NEWTONMETHOD_H
#define NEWTONMETHOD_H

#include "../Utilities/Function.h"

//! NewtonMethod class.
/*!
 NewtonMethod class solve the equation f(x) = 0, finding x0 such that f(x0) = 0
 */

class NewtonMethod
{
public:
    //! Constructor.
    /*!
     The constructor take the starting parameter y0 and an instance of the class Function (or better, an instance of a derived class of Function, as Function is pure virtual) that contains the function f(x) and its derivative. The tolerance of the iterative method and the maximum number of iterations (Newton converge extremely fast if the starting point is close to the solution, but can have a non converging or diverging behaviour if the starting point is not choosen wisely) are optional parameters.
     */
    NewtonMethod(double y0_, Function* F, double tol_ = 1e-6, int maxiter_ = 1000);
    
    //! Solver.
    /*!
     This function effectively solve the problem and return x0 such that f(x0)=0
     */
    double solve() const;
    
    //! Set/reset the method.
    /*!
     This function has the same arguments than the constructor and can be used to reset the method. This allow us to use the same instance of the Newton method with different functions.
     */
    void set(double y0_, Function* F, double tol_ = 1e-6, int maxiter_ = 1000);

private:
    //! Function.
    /*!
     A derived class of the class Function (that is pure virtual) is stored here. This contains at least the function f(x) and its derivative f'(x) nedeed to solve the problem.
     */
    Function* F;
    
    //! Starting point.
    /*!
     To ensure convergence (that is normally fast) it is recomended to choose a starting point close to the (guessed) solution.
     */
    double y0;
    
    //! Tolerance.
    /*!
     Exit condition of the iterative method. The iterative method stops when |f(x_old)-f(x_new)| < tol
     */
    double tol;
    
    //! Maximal number of iterations.
    /*!
     If the starting point y0 is not choosen wisely the Newton method can oscillate between two points or diverge. The maximal number of iterations avoids infinite loops.
     */
    int maxiter;
};

#endif