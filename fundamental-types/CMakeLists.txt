include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( fundamental-types VERSION 1.0 )

configure_build_dirs( . )
add_executable( FundamentalTypes ${CMAKE_SOURCE_ROOT_DIR}/FundamentalTypes.cpp )