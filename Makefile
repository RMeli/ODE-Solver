CC  = g++
CXX = g++

CXXFLAGS= -std=c++11 -Wall -O3

all: TEST_EulerIntegrator

TEST_EulerIntegrator: TEST_EulerIntegrator.o Integrator.o EulerIntegrator.o

TEST_EulerIntegrator.o: TEST_EulerIntegrator.cpp EulerIntegrator.h

Integrator.o: Integrator.cpp Integrator.h

EulerIntegrator.o: EulerIntegrator.cpp EulerIntegrator.h

clean:
	rm -f *.o