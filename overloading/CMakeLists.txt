include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( overloading VERSION 1.0 )

configure_build_dirs( . )
add_executable( Overloading ${CMAKE_SOURCE_ROOT_DIR}/Overloading.cpp )