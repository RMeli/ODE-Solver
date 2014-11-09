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
    NewtonMethod(double y0_ = 0, double x_ = 0, double (*fxy_)(double,double) = nullptr, double (*dyfxy_)(double,double) = nullptr, double tol_ = 1e-6, int maxiter_ = 1000);
    
    double solve() const;
    
    void set_function(double (*f)(double,double), double (*df)(double,double));
    
    void set_tol(double tol_);
    void set_maxiter(int maxiter_);

private:
    double (*fxy)(double,double);
    double (*dyfxy)(double,double);
    double y0;
    double x;
    double tol;
    int maxiter;
};

#endif