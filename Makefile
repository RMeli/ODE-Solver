CC  = g++
CXX = g++

CXXFLAGS= -std=c++11 -Wall -O3

all: TESTS

TESTS: TEST_EulerIntegrator TEST_RungeKutta4

TEST_EulerIntegrator: TEST_EulerIntegrator.o Integrator.o EulerIntegrator.o

TEST_RungeKutta4: TEST_RungeKutta4.o Integrator.o RungeKutta4.o

TEST_EulerIntegrator.o: TEST_EulerIntegrator.cpp EulerIntegrator.h

TEST_RungeKutta4.o: TEST_RungeKutta4.cpp RungeKutta4.h

Integrator.o: Integrator.cpp Integrator.h

EulerIntegrator.o: EulerIntegrator.cpp EulerIntegrator.h Integrator.h

RungeKutta4.o: RungeKutta4.cpp RungeKutta4.h Integrator.h

clean:
	rm -f *.o