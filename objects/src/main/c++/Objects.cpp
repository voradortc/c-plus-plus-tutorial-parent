#include "Objects.h"
#include <iostream>

int ObjectDate::id{ 1000 };

int ObjectDate::setId() {
    return ++id;
}

void ObjectDate::print() const {
    std::cout << "Id: " << dateId << " (Day: " << day << ", Month: " << month << ", Year: " << year << ")" << std::endl;
}

int ObjectDate::getCurrentId() {
    return id;
}

int main() {
    ObjectDate{}.print();
    ObjectDate{ 2020, 5, 20 }.print();
    ObjectDate{ 5, 20 }.print();

    std::cout << "The last created id was: " << ObjectDate::getCurrentId() << std::endl;
    return 0;
}