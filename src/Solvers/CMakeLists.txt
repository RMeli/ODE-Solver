add_library(Solver Solver.cpp)
target_include_directories (Solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(AnalyticalSolver AnalyticalSolver.cpp)
target_include_directories (AnalyticalSolver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})