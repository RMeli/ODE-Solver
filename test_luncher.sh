#!/bin/bash

./TEST_EulerIntegrator > testFE.dat
./TEST_RungeKutta2 > testRK2.dat
./TEST_RungeKutta4 > testRK4.dat

gnuplot << EOF
	f(x) = exp(x)

	set key top left
	plot "testFE.dat" w p t "FE","testRK2.dat" w p t "RK2" ,"testRK4.dat" w p t "RK4", f(x) w l t "AS"
EOF

rm *.dat