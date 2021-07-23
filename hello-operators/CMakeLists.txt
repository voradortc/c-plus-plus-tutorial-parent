include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( hello-operators VERSION 1.0 )

configure_build_dirs( . )
add_executable( HelloOperators ${CMAKE_SOURCE_ROOT_DIR}/HelloOperators.cpp )