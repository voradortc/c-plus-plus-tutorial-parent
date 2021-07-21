#include <iostream>
#include <math.h>
#include <string>

class Point3D {
    double x;
    double y;
    double z;

public:
    explicit Point3D( double x = 0.0, double y = 0.0, double z = 0.0 ) : x{ x }, y{ y }, z{ z } {}
    Point3D( const Point3D &point3D ) : x{ point3D.x }, y{ point3D.y }, z{ point3D.z } {}

    operator double() {
        return sqrt( pow( x, 2.0 ) + pow( y, 2.0 ) + pow( z, 2.0 ) );
    }

    Point3D &operator=( const Point3D &point3D ) {
        x = point3D.x;
        y = point3D.y;
        z = point3D.z;
        return *this;
    }

    Point3D operator+( const Point3D &point3D ) {
        return Point3D{ x + point3D.x, y + point3D.y, z + point3D.z };
    }

    Point3D &operator()() {
        std::cout << "Point3D has a size of " << sizeof( Point3D ) << " bytes" << std::endl;
        return *this;
    }

    Point3D &operator++() {
        x++, y++, z++;
        return *this;
    }

    Point3D operator++( int ) {
        Point3D temp{ *this };
        x++, y++, z++;
        return temp;
    }

    std::string to_string() const {
        return std::string{ std::to_string( x ) + ", " + std::to_string( y ) + ", " + std::to_string( z ) };
    }
};

std::ostream &operator<<( std::ostream &cout, const Point3D &point3D ) {
    return cout << "Point3D( " << point3D.to_string() << " )";
}

int main() {
    Point3D one{ 1.0, 1.0, 1.0 };
    Point3D oneCopy{ one };
    Point3D two;
    two = Point3D{ 2.0, 2.0, 2.0 };

    one();
    std::cout << "One points to: " << &one << std::endl;
    std::cout << "Copy of one points to: " << &oneCopy << std::endl;
    std::cout << "One is: " << one << std::endl;
    std::cout << "Copy of one is: " << oneCopy << std::endl;
    std::cout << "Length of one is: " << static_cast<double>( one ) << std::endl;
    std::cout << "One + Two is: " << one + two << std::endl;
    std::cout << "++One is: " << ++Point3D{ 1.0, 1.0, 1.0 } << std::endl;
    std::cout << "One++ is: " << Point3D{ 1.0, 1.0, 1.0 }++ << std::endl;
    return 0;
}