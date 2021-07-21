#include "Inheritance.h"
#include <iostream>
#include <string>
#include <vector>

int main( int argc, char **argv ) {
    std::vector<organs::Organ*> organs{};
    organs.push_back( new organs::Stomach() );
    organs.push_back( new organs::Brain() );

    for ( organs::Organ *organ : organs ) {
        organ->print();
    }

    std::vector<organs::Organ*>::const_iterator iterator{ organs.cbegin() };
    while ( iterator != organs.cend() ) {
        organs::Organ *organ{ *iterator };
        delete organ;
        ++iterator;
    }

    organs.clear();
    return 0;
}

organs::Organ::Organ( std::string type ) : type{ type } {
    std::cout << "Creating Organ -> ";
}

organs::Organ::~Organ() {
    std::cout << " <- Deleting Organ" << std::endl;
}

organs::Organ *organs::Organ::print() {
    std::cout << "This organ's function is: " << type << std::endl;
    return this;
}

organs::Stomach::Stomach() : Organ{ "Digesting" } {
    std::cout << "Stomach" << std::endl;
}

organs::Stomach::~Stomach() {
    std::cout << "Stomach";
}

organs::Brain::Brain() : Organ{ "Thinking" } {
    std::cout << "Brain" << std::endl;
}

organs::Brain::~Brain() {
    std::cout << "Brain";
}

organs::Brain *organs::Brain::print() {
    std::cout << "I think. ";
    return dynamic_cast<organs::Brain *>( organs::Organ::print() );
}