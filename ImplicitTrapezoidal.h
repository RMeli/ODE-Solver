#ifndef IMPLICITTRAPEZOIDAL_H
#define IMPLICITTRAPEZOIDAL_H

#include "ImplicitIntegrator.h"
#include "Function.h"

class ImplicitTrapezoidal : public ImplicitIntegrator
{
public:
    ImplicitTrapezoidal(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
    double step(double xn, double yn);
    
private:
    class ITFunction : public Function
    {
    public:
        ITFunction(ImplicitTrapezoidal*);
        
        double f(double);
        double df(double);
        
    private:
        ImplicitTrapezoidal* IT;
    };
    
    ITFunction* ITF;
    
};

#endif