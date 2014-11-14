#ifndef IMPLICITEULER_H
#define IMPLICITEULER_H

#include "ImplicitIntegrator.h"

class ImplicitEuler : public ImplicitIntegrator
{
public:
    ImplicitEuler(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
    double step(double xn, double yn);
    
private:
    class IEFunction : public Function
    {
    public:
        IEFunction(ImplicitEuler*);
        
        double f(double);
        double df(double);
        
    private:
        ImplicitEuler* IE;
    };
    
    IEFunction* IEF;
};

#endif