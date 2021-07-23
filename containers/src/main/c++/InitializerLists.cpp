#include <vector>
#include <initializer_list>
#include <iostream>

class IntegerList {
    size_t size;
    std::vector<int> contents;

public:
    IntegerList() = default;

    IntegerList( std::initializer_list<int> contents ) : size{ contents.size() }, contents{ std::vector<int>( contents.size() ) } {
        size_t current = 0;
        
        for ( auto testMember : contents ) {
            this->contents[current++] = testMember;
        }
    }

    inline int *begin() { return &contents[0]; }
    inline int *end() { return &contents[0] + std::size( contents ); }
};

int main() {
    IntegerList list{ 1, 2, 3, 4, 5 };

    for ( int integer : list ) {
        std::cout << integer << " ";
    }

    std::cout << std::endl;

    return 0;
}