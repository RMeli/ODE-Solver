add_library(Integrator INTERFACE)
target_include_directories (Integrator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ExplicitIntegrator INTERFACE)
target_include_directories (ExplicitIntegrator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ImplicitIntegrator INTERFACE)
target_include_directories (ImplicitIntegrator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})