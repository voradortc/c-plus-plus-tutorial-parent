include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( functions VERSION 1.0 )

configure_build_dirs( . )
add_executable( Functions ${CMAKE_SOURCE_ROOT_DIR}/Functions.cpp )