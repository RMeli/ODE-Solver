#ifndef NEWTONMETHOD_H
#define NEWTONMETHOD_H

//! NewtonMethod class.
/*!
 NewtonMethod class solve the equation f(x,y) = 0 with respect to y, i.e. find y such that f(x,y) = 0.
 x is a fixed parameter needed because this newton method will be used by implicit ODE solvers that try to solve
 a Cauchy problem of the type y' = f(x,y).
 */

class NewtonMethod
{
public:
    NewtonMethod(double y0_ = 0, double (*f_)(double) = nullptr, double (*df_)(double) = nullptr, double tol_ = 1e-6, int maxiter_ = 1000);
    
    double solve() const;
    
    void set(double y0_, double (*f_)(double), double (*df_)(double), double tol_ = 1e-6, int maxiter_ = 1000);

private:
    double (*f)(double);
    double (*df)(double);
    double y0;
    double tol;
    int maxiter;
};

#endif