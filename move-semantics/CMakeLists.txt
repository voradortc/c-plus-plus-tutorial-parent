include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( move-semantics VERSION 1.0 )

configure_build_dirs( . )
add_executable( MoveSemantics ${CMAKE_SOURCE_ROOT_DIR}/MoveSemantics.cpp )