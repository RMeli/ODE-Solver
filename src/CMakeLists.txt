cmake_minimum_required(VERSION 2.6)
project(ODE)

add_subdirectory(ExplicitIntegrators)
add_subdirectory(ImplicitIntegrators)
add_subdirectory(Solvers)
add_subdirectory(NumericalMethods)
add_subdirectory(Tests)