#include <iostream>

struct this_value {
	std::string value1;

this_value(std::string value2) {
value1 = value2;
}

void funkcja() const {
std::cout << "value of this: " << this -> value1 << "\n";
}
};

auto main() -> int {
	this_value value1("message");
	value1.funkcja();
	
	std::cout << "manual value of this: " << &value1.value1 << "\n";

return 0;
}
