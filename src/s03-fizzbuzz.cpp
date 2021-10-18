#include <iostream>

auto main() -> int
{
auto liczba = std::string{};
std::cout<<"Give a number: ";
std::getline(std::cin, liczba);

for (int i=1;i<=std::stoi(liczba);i++)
{
std::cout<<i<<" ";

if (i%3 == 0){
std::cout<<"Fizz ";
}
if (i%5 == 0){
std::cout<<"Buzz ";
}
std::cout<<"\n";
}
return 0;
}


