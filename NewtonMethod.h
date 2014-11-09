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
    NewtonMethod(double (*fxy_)(double,double), double (*dyfxy_)(double,double), double y0_, double x_, double tol_ = 1e-6);
    
    double solve() const;

private:
    double (*fxy)(double,double);
    double (*dyfxy)(double,double);
    double y0;
    double x;
    double tol;
};

#endif