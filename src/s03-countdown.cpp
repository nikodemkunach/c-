#include <iostream>
#include <string>

auto main (int argc, char* argv[]) -> int {
int liczba = std::stoi(argv[1]);


do {
    std::cout<<liczba<<"...\n";
    liczba--;
} while (liczba >= 0);

return 0;
}

