project( md5 VERSION 1.0 )

configure_build_dirs( . )
add_executable( Md5 ${CMAKE_SOURCE_ROOT_DIR}/Md5.cpp )
target_link_libraries( Md5 ${CONAN_LIBS} )