#ifndef FUNCTION_H
#define FUNCTION_H

//! Class representing a function.
/*!
 This classe represent a function (of any type, from R to R) and occasionally
 its derivative (nullptr otherwise). This class is pure virtual, therefore to
 define a Function we have to create a derived class, where we can provide a
 constructor and maybe some private members. In the library a derived class of
 Function will be defined as a private nasted class in each ImplicitIntegrator
 in order to use the NewtonMethod (that take a Function as an argument) while
 having the function that defines the method as a private member of the method
 itself.
 */
class Function {
public:
  //! Function f.
  /*!
   */
  virtual double f(double) = 0;

  //! Derivative of f.
  /*!
   */
  virtual double df(double) = 0;

  //! Destructor.
  /*!
   Destructor is declared virtual.
   */
  virtual ~Function(){};
};

#endif