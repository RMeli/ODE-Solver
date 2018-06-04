add_library(EulerIntegrator INTERFACE)
target_include_directories (EulerIntegrator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(RungeKutta2 INTERFACE)
target_include_directories (RungeKutta2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(RungeKutta4 INTERFACE)
target_include_directories (RungeKutta4 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})