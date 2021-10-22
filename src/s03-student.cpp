#include <iostream>
#include <string>
#include "Student.h"

s25030::Student::Student(
	std::string imie,
	std::string nazwisko,
	std::string idnumber,
	unsigned short semestr,
	double srednia) : imie{imie}, nazwisko{nazwisko}, idnumber{idnumber}, semestr{semestr}, srednia{srednia}
{}

auto s25030::Student::to_string() const -> std::string {
	std::cout<< "Imie: " << imie << "\n";
	std::cout<< "Nazwisko: " << nazwisko << "\n";
	std::cout<< "Id number: " << idnumber << "\n";
	std::cout<< "Semestr: " << semestr << "\n";
	std::cout<< "Srednia: " << srednia << "\n";

	return 0;
	}
 

auto main() -> int {
	auto const student = s25030::Student{"Student", "Studencki", "s12345", 1, 4.268};
		std::cout << student.to_string() << "\n";
		return 0;
	}

