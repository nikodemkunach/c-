#include <string>
#include <iostream>
namespace s25030 {
    struct Student {
    
        std::string const imie;
        std::string const nazwisko;
        std::string const idnumber;
        unsigned short semestr;
        double srednia;
    

    Student(std::string, std::string, std::string, unsigned short, double);
    auto to_string() const -> std::string;
    
    };
}

