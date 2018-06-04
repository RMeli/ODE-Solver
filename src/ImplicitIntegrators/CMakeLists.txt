add_library(ImplicitEuler INTERFACE)
target_include_directories (ImplicitEuler INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ImplicitMidpoint INTERFACE)
target_include_directories (ImplicitMidpoint INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ImplicitTrapezoidal INTERFACE)
target_include_directories (ImplicitTrapezoidal INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})