add_library(Integrator Integrator.cpp)
target_include_directories (Integrator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ExplicitIntegrator ExplicitIntegrator.cpp)
target_include_directories (ExplicitIntegrator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ImplicitIntegrator ImplicitIntegrator.cpp)
target_include_directories (ImplicitIntegrator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})