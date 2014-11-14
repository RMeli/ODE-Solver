#ifndef IMPLICITMIDPOINT_H
#define IMPLICITMIDPOINT_H

#include "ImplicitIntegrator.h"
#include "Function.h"

class ImplicitMidpoint : public ImplicitIntegrator
{
public:
    ImplicitMidpoint(double (*ODE_)(double,double), double dx_, double (*dODE_)(double,double));
    
    double step(double xn, double yn);
    
private:
    class IMFunction : public Function
    {
    public:
        IMFunction(ImplicitMidpoint*);
        
        double f(double);
        double df(double);
        
    private:
        ImplicitMidpoint* IM;
    };
    
    IMFunction* IMF;

};

#endif