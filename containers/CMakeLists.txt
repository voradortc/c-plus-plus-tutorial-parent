include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( containers VERSION 1.0 )

configure_build_dirs( . )
add_executable( InitializerLists ${CMAKE_SOURCE_ROOT_DIR}/InitializerLists.cpp )