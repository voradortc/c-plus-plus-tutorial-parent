project( move-semantics VERSION 1.0 )

configure_build_dirs( . )
add_executable( MoveSemantics ${CMAKE_SOURCE_ROOT_DIR}/MoveSemantics.cpp )