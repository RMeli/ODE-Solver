CC  = g++
CXX = g++

CXXFLAGS= -std=c++11 -Wall -O3

all: TESTS

TESTS: TEST_EulerIntegrator TEST_RungeKutta2 TEST_RungeKutta4 TEST_Solver TEST_NewtonMethod TEST_ImplicitEuler TEST_Function TEST_ImplicitMidpoint TEST_ImplicitTrapezoidal TEST_ImplicitSolver

###############
# EXECUTABLES #
###############

TEST_EulerIntegrator: TEST_EulerIntegrator.o Integrator.o EulerIntegrator.o

TEST_RungeKutta2: TEST_RungeKutta2.o Integrator.o RungeKutta2.o

TEST_RungeKutta4: TEST_RungeKutta4.o Integrator.o RungeKutta4.o

TEST_Solver: TEST_Solver.o Solver.o Integrator.o EulerIntegrator.o RungeKutta2.o RungeKutta4.o

TEST_NewtonMethod: TEST_NewtonMethod.o NewtonMethod.o

TEST_ImplicitEuler: TEST_ImplicitEuler.o ImplicitEuler.o ImplicitIntegrator.o NewtonMethod.o

TEST_Function: TEST_Function.o

TEST_ImplicitMidpoint: TEST_ImplicitMidpoint.o ImplicitIntegrator.o ImplicitMidpoint.o NewtonMethod.o

TEST_ImplicitTrapezoidal: TEST_ImplicitTrapezoidal.o ImplicitIntegrator.o ImplicitTrapezoidal.o NewtonMethod.o

TEST_ImplicitSolver: TEST_ImplicitSolver.o ImplicitSolver.o ImplicitEuler.o ImplicitMidpoint.o ImplicitTrapezoidal.o ImplicitIntegrator.o NewtonMethod.o

################
# OBJECT FILES #
################

# Tests

TEST_EulerIntegrator.o: TEST_EulerIntegrator.cpp EulerIntegrator.h

TEST_RungeKutta2.o: TEST_RungeKutta2.cpp RungeKutta2.h

TEST_RungeKutta4.o: TEST_RungeKutta4.cpp RungeKutta4.h

TEST_Solver.o: TEST_Solver.cpp Solver.h EulerIntegrator.h RungeKutta2.h RungeKutta4.h

TEST_NewtonMethod.o: TEST_NewtonMethod.cpp NewtonMethod.h

TEST_ImplicitEuler.o: TEST_ImplicitEuler.cpp ImplicitEuler.h

TEST_Function.o: TEST_Function.cpp Function.h

TEST_ImplicitMidpoint.o: TEST_ImplicitMidpoint.cpp ImplicitMidpoint.h

TEST_ImplicitTrapezoidal.o: TEST_ImplicitTrapezoidal.cpp ImplicitTrapezoidal.h

TEST_Solver.o: TEST_ImplicitSolver.cpp ImplicitSolver.h ImplicitEuler.h ImplicitMidpoint.h ImplicitTrapezoidal.h

# Explicit

Integrator.o: Integrator.cpp Integrator.h

ImplicitIntegrator.o: ImplicitIntegrator.cpp ImplicitIntegrator.h

EulerIntegrator.o: EulerIntegrator.cpp EulerIntegrator.h Integrator.h

ImplicitEuler.o: ImplicitEuler.cpp ImplicitEuler.h ImplicitIntegrator.h

RungeKutta2.o: RungeKutta2.cpp RungeKutta2.h Integrator.h

RungeKutta4.o: RungeKutta4.cpp RungeKutta4.h Integrator.h

ImplicitMidpoint.o: ImplicitMidpoint.cpp ImplicitMidpoint.h ImplicitIntegrator.h

ImplicitTrapezoidal.o: ImplicitTrapezoidal.cpp ImplicitTrapezoidal.h ImplicitIntegrator.h

# Utilities

Solver.o: Solver.cpp Solver.h Integrator.h

ImplicitSolver.o: ImplicitSolver.cpp ImplicitSolver.h ImplicitIntegrator.h

NewtonMethod.o: NewtonMethod.cpp NewtonMethod.h

clean:
	rm -f *.o
	
cleanall:
	rm -f *.o *.dat TEST_EulerIntegrator TEST_RungeKutta2 TEST_RungeKutta4 TEST_Solver TEST_NewtonMethod TEST_ImplicitEuler TEST_Function TEST_ImplicitMidpoint TEST_ImplicitTrapezoidal TEST_ImplicitSolver