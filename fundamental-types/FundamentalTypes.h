#ifndef FUNDAMENTAL_TYPES_H
#define FUNDAMENTAL_TYPES_H

#pragma once

#include <cstddef>
#include <string>

namespace fundamental {
    template<typename T>
    void createAndPrintRandomVariable();

    template<typename T>
    T *createRandomVariable();

    template<typename T>
    void printTypeData( T *ptr );
    
    template<typename T>
    void printMemoryAddress( T *ptr );
    
    template<typename T>
    void printSize( T *ptr );
    
    template<typename T>
    void printBinaryValue( T *ptr );
    
    template<typename T>
    void printHexadecimalValue( T *ptr );

    template<typename T>
    void printDecimalValue( T *ptr );
    
    constexpr std::string_view HEADER{ "========================================================================================================================================================" };
    constexpr std::size_t BITS{ 8 };
}

#endif