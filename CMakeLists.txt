cmake_minimum_required(VERSION 3.0)
project(ODE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src/Integrators)
add_subdirectory(src/ExplicitIntegrators)
add_subdirectory(src/ImplicitIntegrators)
add_subdirectory(src/Solvers)
add_subdirectory(src/NumericalMethods)
add_subdirectory(src/Tests)

option(COVERAGE "Use code coverage if compiler is Clang" OFF)
if(COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CLANG_COVERAGE_COMPILE_FLAGS "--coverage -g -O0")
    set(CLANG_COVERAGE_LINK_FLAGS    "--coverage")

    message("-- Code coverage enabled: ${CLANG_COVERAGE_COMPILE_FLAGS}")

    set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${CLANG_COVERAGE_COMPILE_FLAGS}" )
    set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CLANG_COVERAGE_COMPILE_FLAGS}" )
    set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${CLANG_COVERAGE_LINK_FLAGS}" )
endif()

enable_testing()

add_test(UNITTEST_NewtonMethod bin/TEST_NewtonMethod)
add_test(UNITTEST_EulerIntegrator bin/TEST_EulerIntegrator)
add_test(UNITTEST_RungeKutta2 bin/TEST_RungeKutta2)
add_test(UNITTEST_RungeKutta4 bin/TEST_RungeKutta4)
add_test(UNITTEST_ImplicitEuler bin/TEST_ImplicitEuler)
add_test(UNITTEST_ImplicitMidpoint bin/TEST_ImplicitMidpoint)
add_test(UNITTEST_ImplicitTrapezoidal bin/TEST_ImplicitTrapezoidal)
add_test(UNITTEST_Solver bin/TEST_Solver)
add_test(UNITTEST_AnalyticalSolver bin/TEST_AnalyticalSolver)
