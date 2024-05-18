#include "printables.hpp"

template <typename T>
void print1(T t) requires is_printable_v<T>
{
    std::cout << t;
}

template <Printable T>
void print2(T t)
{
    std::cout << t;
}

int main()
{
    int n = 17;
    char c = 'n';

    print1(c);
    std::cout << " = ";
    print2(n);
    std::cout << "\n[Press ENTER to exit] ";

    std::cin.get();
    return 0;
}
