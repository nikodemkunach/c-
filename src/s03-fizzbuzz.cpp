#include <iostream>

auto main (int argc, char* argv[]) -> int {
int liczba = std::stoi(argv[1]);

for (int i=1; i<=liczba; i++) {
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


