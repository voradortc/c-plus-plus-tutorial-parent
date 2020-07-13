#include <iostream>

namespace internal {
    int aFunction( int );
}

int main() {
    std::cout << internal::aFunction( 52 );
}

namespace internal {
    int aFunction( int x ) {
        return 2 * x;
    }
}