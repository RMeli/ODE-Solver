#ifndef FUNCTION_H
#define FUNCTION_H


//! Class representing a function.
/*!
 This classe represent a function (of any type, from R to R) and occasionally its derivative (nullptr otherwise).
 */
class Function
{
public:
    virtual double f(double) = 0;
    virtual double df(double) = 0;
};

#endif