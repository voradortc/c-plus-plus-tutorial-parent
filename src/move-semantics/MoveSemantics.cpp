#include <iostream>
#include <memory>
#include <utility>

template<class T>
class PointerHolder {
    T *ptr;

public:
    PointerHolder( T *ptr = nullptr ) : ptr{ ptr } {}
    
    PointerHolder( const PointerHolder &instance ) = delete;

    PointerHolder( PointerHolder &&instance ) : ptr{ instance.ptr } {
        instance.ptr = nullptr;
    }
    
    ~PointerHolder() {
        delete ptr;
    }

    PointerHolder &operator=( const PointerHolder &&instance ) = delete;
 
    PointerHolder &operator=( PointerHolder &&instance ) {
        if ( &instance != this ) {
            delete ptr;
            ptr = instance.ptr;
            instance.ptr = nullptr;
        }
        
        return *this;
    }
};
 
class Resource {
public:
    Resource() {
        std::cout << "Resource acquired" << std::endl;
    }

    ~Resource() {
        std::cout << "Resource destroyed" << std::endl;
    }
};
 
PointerHolder<Resource> generateResource() {
    PointerHolder<Resource> resource{ new Resource };
    return resource;
}

int main() {
    {
        PointerHolder<Resource> copyAssignResource;
        copyAssignResource = generateResource();
        
        PointerHolder<Resource> copyConstructResource{ std::move( copyAssignResource ) };
    }
    
    {
        auto uniquePtrResource{ std::make_unique<Resource>() };
        std::unique_ptr<Resource> finalUniquePtrResource{ std::move( uniquePtrResource ) };
        std::cout << "Is uniquePtrResource pointing to anything? " << std::boolalpha << static_cast<bool>( uniquePtrResource ) << std::endl;
    }

    {
        auto sharedPtrResource{ std::make_shared<Resource>() };
        
        {
            std::shared_ptr<Resource> anotherSharedPtrResource{ sharedPtrResource };
            std::cout << "Is anotherSharedPtrResource pointing to anything? " << std::boolalpha << static_cast<bool>( anotherSharedPtrResource ) << std::endl;
        }
        
        std::cout << "Is sharedPtrResource pointing to anything? " << std::boolalpha << static_cast<bool>( sharedPtrResource ) << std::endl;
    }

    return 0;
}