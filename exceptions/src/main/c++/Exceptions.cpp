#include <chrono>
#include <cstdlib>
#include <exception>
#include <iostream>

double divide( int x, int y ) {
    if ( !y ) {
        throw std::invalid_argument{ "The divisor cannot be 0" };
    }

    return static_cast<double>( x ) / static_cast<double>( y );
}

int main( int argc, char **argv ) {
    using namespace std::chrono;
    std::srand( duration_cast<milliseconds>( high_resolution_clock::now().time_since_epoch() ).count() );

    try {
        for ( int i = 0 ; i < 10 ; i++ ) {
            int dividend{ std::rand() };
            int divisor{ i != 9 ? std::rand() : 0 };
            
            try {
                double result{ divide( dividend, divisor ) };
                std::cout << dividend << " / " << divisor << " = " << result << std::endl;
            } catch ( std::exception &exception ) {
                std::cerr << exception.what() << std::endl;
                throw;
            }
        }

    } catch ( ... ) {
        std::cerr << "Catch-all caught something" << std::endl;
    }

    return 0;
}