#include <iostream>

auto main () -> int {

srand(time(NULL));
int zgaduj = rand() % 100 + 1;
std::cout<<zgaduj<<"\n";
int liczba;

do {
std::cout<<"Guess: ";
std::cin>>liczba;
    
    if (liczba>zgaduj) {
        std::cout<<"number is too big!\n;";
    } else if (liczba<zgaduj){
        std::cout<<"number is too low!\n;";
    } else if (liczba == zgaduj){
    break;
}
}
while (true); {
        std::cout<<"just right! \n";
}
return 0;
}
