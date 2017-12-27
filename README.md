# Nonlinear First Order Ordinary Differential Equations 

The aim of this project is to develop a library to solve scalar ODEs defined by a general nonlinear function f(x,y). The ODEs will be of the type

    y' = f(x,y)
    
where y' denote the derivative of y with respect to x. Higher-order ODEs are considered vectorial problems, as any N-order scalar ODE can be transformed into a system of N first-order ODEs, and are not implemented here.

## Numerical Methods

The library will contain both explicit and implicit methods, of different orders.

The explicit methods provided are:
- Explicit Euler
- 2nd order Runge-Kutta
- 4th order Runge-Kutta

The implicit methods provided are:
- Implicit Euler
- Implicit Midpoint
- Implicit Trapezoidal

In addition the library contains the following utilities, that are used by ODEs solvers:
- Newton Method

### Structure

All explicit and implicit methods derive from `Integrator` class, which store the function to integrate and the step length. This class is pure virtual as the function that performs the integration step will be defined in derived classes. `ExplicitIntegrator` and `ImplicitIntegrator` classes differentiate between explicit and implicit methods (implicit methods need also the derivative of f(x,y) in order to use NewtonMethod) but does not implement the pure vistual function step. This function is implemented in further derived class.

A `Solver` class apply an `Integrator` to the problem. The problem is a Cauchy problem, defined by

y' = f(x,y)
y(x0) = y0

The interval [x0,xN] and the initial value y0 are member of the `Solver` class, that also has a pointer to an `Integrator`. The `Integrator` is applied sequentially to the problem in order to obtain the complete solution over [x0,xN]. The solution (xn,yn) is stored as a two-element `std::array` inside a `std::vector`.

In the case of implicit methods we need to solve a nonlinear equation at each step, therefore the `ImplicitIntegrator` class also contain a `NewtonMethod` class that can solve the nonlinear problem. In order to use the `NewtonMethod`, we also need to know the derivative of the function f(x,y) with respect to y. The nonlinear functions defining the methods are derived from the pure virtual class `Function`, that is used by the `NewtonMethod`. This derived classes are defined in the private section of the implicit integrator, in order to keep a restricted access.

### Analysis

It is useful to study the performance of a different ODE solver in order to decide which one to use to solve a given problem (performance, accuracy, ...). A class that compares numerical solution of a given `Integrator` with the exact analytical solution is provided. This class compute both the numerical solution and the analytical one at the same point and compute the absolute and the relative error between the two

## Compilation

### Requirements

CMake 3.0 or later is required in order to compile the library.

The library is written in C++11 and therefore this version of the standars is enforced in the `CMakeList.txt` file.

### Compilation

In order to build the library in Release mode you can type

    mkdir build && cd build
    cmake --CMAKE_BUILD_TYPE=Release ..
    make

## Use

### Testing

## Documentation

The library is documented with Doxygen. To create the documentation just type

    doxygen Doxygen.in
