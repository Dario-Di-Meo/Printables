#ifndef PRINTABLES_HPP
#define PRINTABLES_HPP 1

#include <concepts>
#include <iostream>

// Default definition of the is_printable type trait that is set to false.
template<typename T, typename = void>
struct is_printable : std::false_type {};

// Partial specialization of the is_printable type trait.
// It determines if a type T can be printed to std::cout.
// If so, is_printable is set to true.
template<typename T>
struct is_printable<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>> : std::true_type {};

// Alias for is_printable<T>::value.
template<typename T>
inline constexpr bool is_printable_v = is_printable<T>::value;

// A concept that ensures that a type T can be printed to std::cout.
template<typename T>
concept Printable = requires(T t)
{
    {
        std::cout << t
    };
};    

#endif /* PRINTABLES_HPP */