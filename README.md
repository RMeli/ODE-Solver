# Nonlinear First Order Ordinary Differential Equations 

The aim of this project is to develop a library to solve scalar first-order ODEs defined by a general nonlinear function f(x,y). Therefore, the ODEs that this library can solve are of the type

    y' = f(x,y)
    
where y' denote the derivative of y with respect to x.

Higher-order ODEs are considered vectorial problems, as any N-order scalar ODE can be transformed into a system of N first-order ODEs, and are not implemented here.

### Disclaimer

This library has been written in 2014 for the class **Programming Concepts in Scientific Computing** at *Ecole Polytechnique Fédérale de Lausanne* and was awarded the maximum grade. However my C++ programming skills further developed in recent years (in particular towards more advanced C++11 concepts) and therefore this library does not reflect anymore my programming style nor the level of my programming skills.

I recognise in this library there are conceptual errors. In particular C-style pointers are sometime handled incorrectly. Many errors can now be easily avoided using C++11 concepts such as `std::unique_ptr`. In the same way, cumbersome C-stype syntax for pinters to functions can be altogether avoided using `std::function`.

Some small modifications have been made to this project during in recent years, but the source code remained unchanged and therefore still contains design and programming mistakes.

## Numerical Methods

The library implement explicit and implicit integration methods, of different orders.

The explicit integration methods provided are:
- Euler
- 2nd order Runge-Kutta
- 4th order Runge-Kutta

The implicit integration methods provided are:
- Euler
- Midpoint
- Trapezoidal

In addition the library contains the following utilities, that are used by ODEs solvers:
- Newton Method

### Structure

All explicit and implicit integration methods derive from the class `Integrator`, which store the function to integrate and the step length. This class is pure virtual and the function performing the integration step is defined in derived classes.

`ExplicitIntegrator` and `ImplicitIntegrator` classes differentiate between explicit and implicit integration methods (implicit methods need also the derivative of f(x,y) in order to use NewtonMethod) but do not implement the pure virtual function performin the integration. This function is implemented in further derived class, named after the integration method they implement.

A `Solver` class apply an `Integrator` to the problem. The problem is a Cauchy problem, defined by

    y' = f(x,y)
    y(x0) = y0

The interval [x0,xN] and the initial value y0 are member of the `Solver` class, that also has a pointer to an `Integrator`. The `Integrator` is applied sequentially to the problem in order to obtain the solution over [x0,xN]. The solution (xn,yn) is stored as a two-element `std::array` inside a `std::vector`.

In the case of implicit methods we need to solve a nonlinear equation at each step, therefore the `ImplicitIntegrator` class also contain a `NewtonMethod` class that can solve the nonlinear problem. In order to use the `NewtonMethod`, we need to know the derivative of the function f(x,y) with respect to y. The nonlinear functions defining the methods are derived from the pure virtual class `Function`, that is used by the `NewtonMethod`. These derived classes are defined in the private section of the implicit integrator, in order to keep a restricted access.

### Analysis

It is useful to study the performance of a different ODE solver in order to decide which one to use to solve a given problem (performance, accuracy, ...). A class comparing the numerical solution of a given `Integrator` with the exact analytical solution is provided. This class computes both the numerical solution and the analytical one at the same point and compute the absolute and the relative errors between the two.

## Compilation

### Requirements

The compilation is performed using [CMake](https://cmake.org/). CMake 3.0 or later is required.

The library is written using some C++11 features. This version of the C++ standars is enforced in the `CMakeList.txt` file.

### Compilation

In order to build the library in `Debug` mode you can type

    mkdir build && cd build
    cmake --CMAKE_BUILD_TYPE=Debug ..
    make

while to build the library in `Release` mode (with optimization) you can type

    mkdir build && cd build
    cmake --CMAKE_BUILD_TYPE=Release ..
    make
    
## Documentation

The library is documented with Doxygen. To build the documentation type

    doxygen Doxygen.in
