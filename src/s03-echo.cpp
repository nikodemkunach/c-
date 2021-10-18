#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int {

std::string arg1 = argv[1];
std::string arg2 = argv[2];

for(int i=1; i<argc; i++) {

    if(arg1=="-n") {
        std::cout<<argv[i]<<" ";
    } else if (arg1=="-l") {
        std::cout<<argv[i]<<"\n";
        } else if (arg1=="-r") {
        if(arg2=="-l") {
            std::cout<<argv[argc - i]<<"\n"; 
        } else if (arg2=="-n") {
            std::cout<<argv[argc - i] <<" ";
        } else if (arg1=="-r") {
            std::cout<<argv[argc - i] <<" ";
        }
    } else {
            std::cout<<argv[i]<<" ";
            }
    }
return 0;
}
    


