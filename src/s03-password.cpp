#include <iostream>
#include <string>

auto main(int, char*argv[]) -> int 
{

auto password = std::string{};
std::cout << "password ";
std::getline(std::cin, password);

while (password != "student")
{
	std::cout << "Wrong password \n";
	std ::getline(std::cin, password);
}

if (password == "student")
{
	std::cout << "ok! \n";
}

return 0;

}
