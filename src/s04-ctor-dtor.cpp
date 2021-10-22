#include <iostream>
#include <string>

struct Struct {

    std::string message;
    Struct(std::string msg) {
    message = msg;
    }
    
    ~Struct() {
    std::cout << "DESTRUCTION!" << "\n";
    std::cout << message << "\n";
    }
};

auto main() -> int {

auto a = Struct("message");
return 0;
}
