include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( headers VERSION 1.0 )

configure_build_dirs( . )
add_executable( Headers ${CMAKE_SOURCE_ROOT_DIR}/Headers.cpp )