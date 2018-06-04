#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <functional>

//! Unsolved class.
/*!
 This class, which derive from the general std::exception is used (throwed as an
 exception) when the user try to access the solution contained before the Solver
 was effectively used.
 */
class Unsolved : public std::exception {
public:
  //! Error description.
  /*!
   */
  const char* what() const noexcept { return "Unsolved ODE."; }
};

//! Undefined class.
/*!
 This class, which derive from std::bad_function_call is used (throwed as an
 exception) when methods try to use pointer to functions that are nullptr.
 */
class Undefined : public std::bad_function_call {
public:
  //! Error description.
  /*!
   */
  const char* what() const noexcept { return "Undefined equation to solve."; }
};

#endif