from conans import ConanFile, CMake, tools

class CPLusPlusConan(ConanFile):
    name = "C++"
    version = "1.0"
    license = "ISC"
    author = "Victor Ortiz"
    topics = ("C++", "CMake", "Conan")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    generators = "cmake"
    requires = "poco/1.9.4"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()