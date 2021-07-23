include( ../configuration.cmake )

cmake_minimum_required( VERSION 3.21 )
project( io-stream VERSION 1.0 )

configure_build_dirs( . )
add_executable( IOStream ${CMAKE_SOURCE_ROOT_DIR}/IOStream.cpp )