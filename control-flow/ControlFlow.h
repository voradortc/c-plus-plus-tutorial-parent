#ifndef CONTROL_FLOW_H
#define CONTROL_FLOW_H

#pragma once

#include <string>

enum class Title {
    MR,
    MRS,
    NO_TITLE
};

struct Person {
    Title title;
    std::string_view firstName;
    std::string_view lastName;
};

std::string_view names[2][10] {
    { "Andy ", "Clara ", "David ", "Sarah ", "James ", "Cassie ", "Sam ", "Lily ", "Abdul ", "Theodora " },
    { "Smith", "Davis", "Scanlon", "Kerry", "Kelso", "Dorian", "Chalke", "Ortiz", "Stillman", "Ford" }
};

Title selectRandomTitle();
std::string_view &selectRandomFirstName();
std::string_view &selectRandomLastName();
Person *createRandomPerson();
void deletePerson( Person *person );
void printPerson( Person *person );
void print( std::string_view &string );
void print( Title &title );
void sort( Person *persons[], int length, int passes, int ( *sortingFunction )( Person *person1, Person *person2 ) );

#endif