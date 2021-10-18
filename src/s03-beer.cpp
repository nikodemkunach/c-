#include <iostream>

auto main() -> int {

auto liczba = std::string{};
std::cout<<"Give a number to begin song...";
std::getline(std::cin, liczba);
std::cout<<"\n";

for(int i=stoi(liczba); i>=0; i--) {
std::cout<<i<<" bottles of beer on the wall, ";
std::cout<<i<<" bottles of beer.\n";
std::cout<<"Take one down, pass it around, ";
std::cout<<i<<" bottles of beer on the wall...\n";
std::cout<<"\n";
}
std::cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
std::cout << "Go to the store and buy some more, ";
std::cout<<liczba<<" bottles of beer on the wall...\n";
std::cout<<"\n";
return 0;
}
