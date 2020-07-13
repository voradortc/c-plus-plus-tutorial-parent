#include <iostream>

int main() {
    int x{ 0 };
    int y{ 1 };

    std::cout << "+1 is: " << +1 << std::endl;
    std::cout << "-1 is: " << -1 << std::endl;
    std::cout << "1 + 1 is: " << 1 + 1 << std::endl;
    std::cout << "3 - 1 is: " << 3 - 1 << std::endl;
    std::cout << "2 * 3 is: " << 2 * 3 << std::endl;
    std::cout << "2 / 3 is: " << 2.0 / 3.0 << std::endl;
    std::cout << "7 % 3 is: " << 7 % 3 << std::endl;
    std::cout << "++x is: " << ++x << std::endl;
    std::cout << "x++ is: " << x++ << std::endl;
    std::cout << "--x is: " << --x << std::endl;
    std::cout << "x-- is: " << x-- << std::endl;
    std::cout << "1 > 2 is: " << ( 1 > 2 ) << std::endl;
    std::cout << "1 < 2 is: " << ( 1 < 2 ) << std::endl;
    std::cout << "1 >= 2 is: " << ( 1 >= 2 ) << std::endl;
    std::cout << "1 <= 2 is: " << ( 1 <= 2 ) << std::endl;
    std::cout << "1 == 2 is: " << ( 1 == 2 ) << std::endl;
    std::cout << "1 != 2 is: " << ( 1 != 2 ) << std::endl;
    std::cout << "!x is: " << ( !x ) << std::endl;
    std::cout << "x && y is: " << ( x && y ) << std::endl;
    std::cout << "x || y is: " << ( x || y ) << std::endl;
    std::cout << "x << 4 is: " << ( x << 4 ) << std::endl;
    std::cout << "x >> 4 is: " << ( x >> 4 ) << std::endl;
    std::cout << "~x is: " << ( ~x ) << std::endl;
    std::cout << "x & 256 is: " << ( x & 256 ) << std::endl;
    std::cout << "x | 256 is: " << ( x | 256 ) << std::endl;
    std::cout << "x ^ 256 is: " << ( x ^ 256 ) << std::endl;
}