#include <iostream>

auto main() -> int {

auto liczba = std::string{};
std::cout<<"Give a number to countdown...";
std::getline(std::cin, liczba);

for(int i=stoi(liczba); i>=0; i--) {
std::cout<<i<<"...\n";
}
for(int i=stoi(liczba); i<=0; i++) {
std::cout<<i<<"...\n";
}
return 0;
}



