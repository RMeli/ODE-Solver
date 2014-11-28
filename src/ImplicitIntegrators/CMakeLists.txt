add_library(ImplicitIntegrator ImplicitIntegrator.cpp)
target_include_directories (ImplicitIntegrator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ImplicitEuler ImplicitEuler.cpp)
target_include_directories (ImplicitEuler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ImplicitMidpoint ImplicitMidpoint.cpp)
target_include_directories (ImplicitMidpoint PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ImplicitTrapezoidal ImplicitTrapezoidal.cpp)
target_include_directories (ImplicitTrapezoidal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})