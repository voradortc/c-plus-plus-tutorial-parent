#include "ControlFlow.h"
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::srand( static_cast<unsigned int>( std::time( nullptr ) ) );
    std::array<Person*, 10> persons{};

    for ( int i = 0 ; i < 10 ; i++ ) {
        persons.at( i ) = createRandomPerson();
    }

    auto sortingFunction{ []( Person *person1, Person *person2 ) -> int { return person1->lastName.compare( person2->lastName ); } };
    sort( persons.data(), persons.size(), persons.size(), sortingFunction );

    for ( auto person : persons ) {
        printPerson( person );
    }

    int i{ 0 };
    while ( i < 10 ) {
        deletePerson( persons.at( i ) );
        persons.at( i ) = nullptr;
        ++i;
    }

    return 0;
}

Title selectRandomTitle() {
    int random{ std::rand() % 2 };
    switch ( random ) {
        case 0:
            return Title::MR;
        case 1:
            return Title::MRS;
        default:
            return Title::NO_TITLE;
    }
}

std::string_view &selectRandomFirstName() {
    int random{ std::rand() % 10 };
    return names[0][random];
}

std::string_view &selectRandomLastName() {
    int random{ std::rand() % 10 };
    return names[1][random];
}

Person *createRandomPerson() {
    Person *person = new Person;
    
    if ( person ) {
        person->title = selectRandomTitle();
        person->firstName = selectRandomFirstName();
        person->lastName = selectRandomLastName();
    }

    return person;
}

void deletePerson( Person *person ) {
    delete person;
}

void printPerson( Person *person ) {
    print( person->title );
    print( person->firstName );
    print( person->lastName );
    std::cout << std::endl;
}

void print( std::string_view &string ) {
    std::cout << string;
}

void print( Title &title ) {
    int random{ std::rand() % 2 };
    switch ( title ) {
        case Title::MR:
            std::cout << "Mr. ";
            break;
        case Title::MRS:
            std::cout << "Mrs. ";
            break;
        case Title::NO_TITLE:
            std::cout << "";
            break;
    }
}

void sort( Person *persons[], int length, int passes, int ( *sortingFunction )( Person *person1, Person *person2 ) ) {
    if ( passes > 0 ) {
        for ( int i{ 1 } ; i < length ; i++ ) {
            int result{ sortingFunction( persons[i - 1], persons[i] ) };
            
            if ( 0 < result ) {
                Person *temp{ persons[i - 1] };
                persons[i - 1] = persons[i];
                persons[i] = temp;
            }
        }

        sort( persons, length, --passes, sortingFunction );
    }
}