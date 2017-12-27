cmake_minimum_required(VERSION 3.0)
project(ODE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src/Integrators)
add_subdirectory(src/ExplicitIntegrators)
add_subdirectory(src/ImplicitIntegrators)
add_subdirectory(src/Solvers)
add_subdirectory(src/NumericalMethods)
add_subdirectory(src/Tests)