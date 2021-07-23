include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( inheritance VERSION 1.0 )

configure_build_dirs( . )
add_executable( Inheritance ${CMAKE_SOURCE_ROOT_DIR}/Inheritance.cpp )