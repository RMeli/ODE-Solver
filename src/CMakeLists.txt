cmake_minimum_required(VERSION 3.0)
project(ODE)

add_subdirectory(Integrators)
add_subdirectory(ExplicitIntegrators)
add_subdirectory(ImplicitIntegrators)
add_subdirectory(Solvers)
add_subdirectory(NumericalMethods)
add_subdirectory(Tests)