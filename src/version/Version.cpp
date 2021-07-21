#include <array>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>

namespace a::b::c {
    inline constexpr std::string_view str{ "hello" };
}

template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum( T... args ) {
    return { sizeof...( T ), ( args + ... ) };
}

int main() {
    auto [numbers, numbersSum] { sum( 1, 2, 3 ) };
    std::cout << a::b::c::str << ' ' << numbers << ' ' << numbersSum << std::endl;
    std::array arr{ 1, 2, 3 };
    std::cout << std::size( arr ) << std::endl;
}