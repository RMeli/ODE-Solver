CC  = g++
CXX = g++

CXXFLAGS= -std=c++11 -Wall -O3

all: TESTS

TESTS: TEST_EulerIntegrator TEST_RungeKutta2 TEST_RungeKutta4 TEST_Solver

###############
# EXECUTABLES #
###############

TEST_EulerIntegrator: TEST_EulerIntegrator.o Integrator.o EulerIntegrator.o

TEST_RungeKutta2: TEST_RungeKutta2.o Integrator.o RungeKutta2.o

TEST_RungeKutta4: TEST_RungeKutta4.o Integrator.o RungeKutta4.o

TEST_Solver: TEST_Solver.o Solver.o Integrator.o EulerIntegrator.o RungeKutta2.o RungeKutta4.o

################
# OBJECT FILES #
################

# Tests

TEST_EulerIntegrator.o: TEST_EulerIntegrator.cpp EulerIntegrator.h

TEST_RungeKutta2.o: TEST_RungeKutta2.cpp RungeKutta2.h

TEST_RungeKutta4.o: TEST_RungeKutta4.cpp RungeKutta4.h

TEST_Solver.o: TEST_Solver.cpp Solver.h EulerIntegrator.h RungeKutta2.h RungeKutta4.h

# Explicit

Integrator.o: Integrator.cpp Integrator.h

EulerIntegrator.o: EulerIntegrator.cpp EulerIntegrator.h Integrator.h

RungeKutta2.o: RungeKutta2.cpp RungeKutta2.h Integrator.h

RungeKutta4.o: RungeKutta4.cpp RungeKutta4.h Integrator.h

# Utilities

Solver.o: Solver.cpp Solver.h Integrator.h

clean:
	rm -f *.o