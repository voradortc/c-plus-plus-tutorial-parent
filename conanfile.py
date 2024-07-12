from conan import ConanFile
from conan.tools.cmake import CMake

class CPLusPlusConan(ConanFile):
    name = "c++"
    version = "1.0"
    license = "ISC"
    author = "Victor Ortiz"
    topics = ( "C++", "CMake", "Conan" )
    settings = "os", "compiler", "build_type", "arch"
    options = { "shared": [True, False], "fPIC": [True, False] }
    default_options = { "shared": False, "fPIC": True }
    generators = "CMakeDeps", "CMakeToolchain"
    requires = "poco/1.13.2"

    def config_options( self ):
        if self.settings.os == "Windows":
            self.options.rm_safe( "fPIC" )

    def build( self ):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()