include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( exceptions VERSION 1.0 )

configure_build_dirs( . )
add_executable( Exceptions ${CMAKE_SOURCE_ROOT_DIR}/Exceptions.cpp )