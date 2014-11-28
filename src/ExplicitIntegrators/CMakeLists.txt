add_library(Integrator Integrator.cpp)
target_include_directories (Integrator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(EulerIntegrator EulerIntegrator.cpp)
target_include_directories (EulerIntegrator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(RungeKutta2 RungeKutta2.cpp)
target_include_directories (RungeKutta2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(RungeKutta4 RungeKutta4.cpp)
target_include_directories (RungeKutta4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})