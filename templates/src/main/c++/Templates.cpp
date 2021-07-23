#include <iostream>
#include <string>

template <typename T>
class Container {
    T x;

public:
    Container( T x ) : x{ x } {}
    void print() {
        std::cout << x << std::endl;
    }
};

template <typename T>
T add( T x, T y ) {
    return x + y;
}

double add( double x, double y ) {
    return x + y + 3.1416;
}

int main( int argc, char **argv ) {
    std::cout << argv[0] << std::endl;
    
    std::cout << add( 1, 2 ) << std::endl;
    std::cout << add( std::string{ "1" }, std::string{ "2" } ) << std::endl;
    std::cout << add( 1.1, 2.2 ) << std::endl;

    Container{ 2 }.print();
    Container{ "Hello!" }.print();
    Container{ 2.2 }.print();

    return 0;
}