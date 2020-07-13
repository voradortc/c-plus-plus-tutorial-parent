#include "FundamentalTypes.h"
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main( int argc, char **argv ) {
    std::srand( static_cast<unsigned int>( std::time( nullptr ) ) );
    std::cout << argv[0] << std::endl << std::endl;

    fundamental::createAndPrintRandomVariable<short>();
    fundamental::createAndPrintRandomVariable<int>();
    fundamental::createAndPrintRandomVariable<long>();
    fundamental::createAndPrintRandomVariable<long long>();
    fundamental::createAndPrintRandomVariable<float>();
    fundamental::createAndPrintRandomVariable<double>();
    fundamental::createAndPrintRandomVariable<long double>();
    fundamental::createAndPrintRandomVariable<unsigned short>();
    fundamental::createAndPrintRandomVariable<unsigned int>();
    fundamental::createAndPrintRandomVariable<unsigned long>();
    fundamental::createAndPrintRandomVariable<unsigned long long>();
    fundamental::createAndPrintRandomVariable<std::int16_t>();
    fundamental::createAndPrintRandomVariable<std::int32_t>();
    fundamental::createAndPrintRandomVariable<std::int64_t>();
    fundamental::createAndPrintRandomVariable<std::uint16_t>();
    fundamental::createAndPrintRandomVariable<std::uint32_t>();
    fundamental::createAndPrintRandomVariable<std::uint64_t>();
    fundamental::createAndPrintRandomVariable<std::int_fast16_t>();
    fundamental::createAndPrintRandomVariable<std::int_fast32_t>();
    fundamental::createAndPrintRandomVariable<std::int_fast64_t>();
    fundamental::createAndPrintRandomVariable<std::uint_fast16_t>();
    fundamental::createAndPrintRandomVariable<std::uint_fast32_t>();
    fundamental::createAndPrintRandomVariable<std::uint_fast64_t>();
    fundamental::createAndPrintRandomVariable<std::int_least16_t>();
    fundamental::createAndPrintRandomVariable<std::int_least32_t>();
    fundamental::createAndPrintRandomVariable<std::int_least64_t>();
    fundamental::createAndPrintRandomVariable<std::uint_least16_t>();
    fundamental::createAndPrintRandomVariable<std::uint_least32_t>();
    fundamental::createAndPrintRandomVariable<std::uint_least64_t>();
    fundamental::createAndPrintRandomVariable<wchar_t>();
    fundamental::createAndPrintRandomVariable<char16_t>();
    fundamental::createAndPrintRandomVariable<char32_t>();
    return 0;
}

namespace fundamental {
    template<typename T>
    void createAndPrintRandomVariable() {
        T *ptr{ fundamental::createRandomVariable<T>() };
        fundamental::printTypeData( ptr );
    }

    template<typename T>
    T *createRandomVariable() {
        static const std::size_t bytes{ sizeof( T ) };
        void *ptr{ std::malloc( bytes ) };

        for ( std::int8_t i = bytes - 1 ; i >= 0 ; --i ) {
            std::uint8_t *tempPtr{ static_cast<std::uint8_t *>( ptr ) + i };
            *tempPtr = 0;

            for ( std::int8_t j = 0 ; j < BITS ; ++j ) {
                *tempPtr |= std::rand() % 2;

                if ( j < ( BITS - 1 ) ) {
                    *tempPtr <<= 1;
                }
            }
        }

        return static_cast<T *>( ptr );
    }

    template<typename T>
    void printTypeData( T *ptr ) {
        std::cout << HEADER << std::endl;
        std::cout << "Variable type is:\t" << typeid( *ptr ).name() << std::endl;

        printMemoryAddress( ptr );
        printSize( ptr );
        printBinaryValue( ptr );
        printDecimalValue( ptr );
        printHexadecimalValue( ptr );

        std::free( ptr );
    }

    template<typename T>
    void printMemoryAddress( T *ptr ) {
        void* actualPtr{ ptr };
        std::cout << "Memory address is:\t" << actualPtr << std::endl;
    }

    template<typename T>
    void printSize( T *ptr ) {
        std::size_t size{ sizeof( *ptr ) };
        std::cout << "Size in bytes is:\t" << size << std::endl;
    }

    template<typename T>
    void printBinaryValue( T *ptr ) {
        static const std::size_t bytes{ sizeof( T ) };
        std::bitset<bytes * BITS> binaryValue{};

        for ( std::int8_t i = bytes - 1 ; i >= 0 ; --i ) {
            binaryValue |= *( ( ( std::uint8_t* ) ptr ) + i );

            if ( i > 0 ) {
                binaryValue <<= BITS;
            }
        }

        std::cout << "Binary value is:\t" << binaryValue << std::endl;
    }

    template<typename T>
    void printHexadecimalValue( T *ptr ) {
        std::cout << "Hexadecimal value is:\t" << std::hex << *ptr << std::endl;
    }

    template<typename T>
    void printDecimalValue( T *ptr ) {
        std::cout << "Decimal value is:\t" << std::dec << *ptr << std::endl;
    }
}