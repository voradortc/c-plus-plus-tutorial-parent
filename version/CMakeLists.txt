include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( version VERSION 1.0 )

configure_build_dirs( . )
add_executable( Version ${CMAKE_SOURCE_ROOT_DIR}/Version.cpp )