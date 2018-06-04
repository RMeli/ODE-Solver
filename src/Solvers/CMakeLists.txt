add_library(Solver INTERFACE)
target_include_directories (Solver INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(AnalyticalSolver INTERFACE)
target_include_directories (AnalyticalSolver INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})