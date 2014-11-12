#ifndef FUNCTION_H
#define FUNCTION_H


//! Class representing a function.
/*!
 This classe represent a function (of any type, from R to R) and occasionally its derivative (nullptr otherwise).
 
 This class is necessary because of the distinction between a (C-like) pointer to a function and a pointer to a member function.
 */
template <typename T>
class Function
{
public:
    Function(double (T::*f_)(double),double (T::*df_)(double) = nullptr);
    
    double feval(double);
    double dfeval(double);
    
private:
    double (T::*f)(double);
    double (T::*df)(double);
};

/*******
 PROBLEM
/*******
 
 An instance of the class is always needed, therefore this approac does not work.
 
 */

template <typename T>
Function<T>::Function(double (T::*f_)(double),double (T::*df_)(double))
: f(f_), df(df_)
{}

template <typename T>
double Function<T>::feval(double x)
{
    return T->f(x);
}

template <typename T>
double Function<T>::dfeval(double x)
{
    return T->df(x);
}

#endif