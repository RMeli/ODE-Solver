add_library(Solver Solver.cpp)
target_include_directories (Solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ImplicitSolver ImplicitSolver.cpp)
target_include_directories (ImplicitSolver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(AnalyticalExplicitSolver AnalyticalExplicitSolver.cpp)
target_include_directories (AnalyticalExplicitSolver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(AnalyticalImplicitSolver AnalyticalImplicitSolver.cpp)
target_include_directories (AnalyticalImplicitSolver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})