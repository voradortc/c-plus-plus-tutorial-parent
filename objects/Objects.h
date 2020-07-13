#ifndef OBJECTS_H
#define OBJECTS_H

#pragma once

#include <iostream>

class ObjectDate {
    static int id;

    int dateId{ 0 };
    int year{ 1970 };
    int month{ 1 };
    int day{ 1 };

    int setId();

public:
    ObjectDate() : dateId{ setId() } {
        std::cout << "Executing default constructor" << std::endl;
    }

    ObjectDate( int year, int month, int day ) : dateId{ setId() }, year{ year }, month{ month }, day{ day } {}
    
    ObjectDate( int month, int day ) : ObjectDate{ 1995, month, day } {}
    
    ~ObjectDate() {
        --id;
        std::cout << "Executing destructor" << std::endl;
    }

    static int getCurrentId();
    void print() const;
};

#endif