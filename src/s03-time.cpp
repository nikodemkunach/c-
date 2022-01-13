#include <iostream>
#include <string>
#include "Time.h"

auto Time::to_string() -> std::string
{
    std::string hours;
    if(hour < 10) 
    {
    hours = "0" + std::to_string(hour);
    }
    else 
    {
    hours = std::to_string(hour);
    }

    std::string minute;
    if(minutes < 10)
    {
    minute = "0" + std::to_string(minutes);
    }
    else
    {
    minute = std::to_string(minutes);
    }

    std::string seconds; 
    if(sec < 10) 
    {
    seconds = "0" + std::to_string(sec);
    }
    else
    {
    seconds = std::to_string(sec);
    }
    return hours + ":" + minute + ":" + seconds;
}

auto Time::next_hour()-> void
{
    hour++;
    if(hour > 23)
    {
        hour = 0;
    }
}

auto Time::next_minute()-> void
{
    minutes++;
    if(minutes > 59)
    {
        minutes = 0;
        next_hour();
    }
}

auto Time::next_second()-> void
{
    sec++;
    if(sec > 59)
    {
        sec = 0;
        next_minute();
    }
}

Time::Time(int h, int m, int s)
    : hour{h}
    , minutes{m}
    , sec{s}
{}

auto Time::time_of_day() const
{
    Time_of_day time;

    if(hour<=6)
    {
    time = Time_of_day::noc;
    }

    else if(hour<=9)
    {
    time = Time_of_day::rano;
    }

    else if(hour<=19)
    {
    time = Time_of_day::dzien;
    }
    else
    {
    time = Time_of_day::wieczor;
    }
    return time; 
}

auto to_string(Time_of_day pora_dnia) -> std::string 
{
    switch(pora_dnia)
    {       
        case Time_of_day::noc:
        return "noc\n";
        break;

        case Time_of_day::rano:
        return "rano\n";
        break;

        case Time_of_day::dzien:
        return "dzien\n";
        break;

        case Time_of_day::wieczor:
        return "wieczor\n";
        break;
        default:
        return  "Brak danych";
    }
    
}
auto Time::operator+ (Time const& p)  const -> Time
{
	auto czas = Time{hour, minutes, sec};
		
	int h, m, s;
	if(hour + p.hour > 24)
	{
		h = hour + p.hour - 24;
	}
	else
    {
    h = hour + p.hour;
	}
    	
	if(minutes + p.minutes > 59)
	{
		m = minutes + p.minutes - 60;
		h++;
	}
	else
    {
	m = minutes + p.minutes;
    }
		
	if(sec + p.sec > 59)
	{
		s = sec + p.sec - 60;
		m++;
	}
	else
    {
	s = sec + p.sec;
    }		
	czas.hour = h;
	czas.minutes = m;
	czas.sec = s;
		
	return czas;
}

auto Time::operator- (Time const& p)  const -> Time
{
	auto czas = Time{hour, minutes, sec};
	
	if(czas < p)
	{
		std::cout << "Nie ma ujemnego czasu." << std::endl;
		return czas;
	}	
	
	int h, m, s;
	
	h = hour - p.hour ;
			
	if(minutes - p.minutes < 0)
	{
		m = minutes - p.minutes + 60;
		h--;
	}
	else
		m = minutes - p.minutes;
		
	if(sec + p.sec < 0 )
	{
		s = sec + p.sec + 60;
		m--;
	}
	else
		s = sec - p.sec;
				
	czas.hour = h;
	czas.minutes = m;
	czas.sec = s;
		
	return czas;
}

auto Time::operator< (Time const &p) const -> bool
{

	if(hour < p.hour)
	{
		return true;
	}
	else if(hour == p.hour)
	{
		if(minutes < p.minutes)
		{
			return true;
		}
		else if(minutes == p.minutes)
		{
			if(sec < p.sec)
			{
				return true;
			}
			else 
				return false;
		}
	} 
	return false;
}

auto Time::operator> (Time const &p) const -> bool
{

	if(hour > p.hour)
	{
		return true;
	}
	else if(hour == p.hour)
	{
		if(minutes > p.minutes)
		{
			return true;
		}
		else if(minutes == p.minutes)
		{
			if(sec > p.sec)
			{
				return true;
			}
			else 
				return false;
		}
	} 
	return false;
}

auto Time::operator== (Time const &p) const -> bool
{
	if(hour == p.hour && minutes == p.minutes && sec == p.sec)
		return true;
	
	return false;
}

auto Time::operator!= (Time const &p) const -> bool
{
	if(hour == p.hour && minutes == p.minutes && sec == p.sec)
		return false;
	
	return true;
}

auto main() -> int
{
    auto czas3 = Time{23,58,58};
    for(auto i=0; i<3; i++)
    {
    std::cout << czas3.to_string()<<"    ";
    
    std::cout << to_string(czas3.time_of_day());

    czas3.next_minute();
    }
    for(auto i=0; i<3; i++)
    {
    std::cout << czas3.to_string()<<"    ";

    std::cout << to_string(czas3.time_of_day());

    czas3.next_second();
    }
   
   auto czas2 = Time{12,1,59};
   auto czas = Time{5,30,1};
   
   std::cout << std::endl; 
   std::cout << czas2.to_string()<< std::endl;
   std::cout << czas.to_string()<< " + " << std::endl;
   std::cout << (czas + czas2).to_string() << std::endl; 
   
   std::cout << std::endl;
   std::cout << czas2.to_string()<< std::endl;
   std::cout << czas.to_string()<< " - " << std::endl;
   std::cout << (czas2 - czas).to_string() << std::endl; 
   
   std::cout << std::endl;
   std::cout << czas2.to_string()<< std::endl;
   std::cout << czas.to_string()<< " < " << std::endl;
   std::cout << (czas2 < czas) << std::endl; 
   
   std::cout << std::endl;
   std::cout << czas2.to_string()<< std::endl;
   std::cout << czas.to_string()<< " > " << std::endl;
   std::cout << (czas2 > czas) << std::endl; 

   std::cout << std::endl;
   std::cout << czas2.to_string()<< std::endl;
   std::cout << czas.to_string()<< " = " << std::endl;
   std::cout << (czas2 == czas) << std::endl;
    
   std::cout << std::endl;
   std::cout << czas2.to_string()<< std::endl;
   std::cout << czas.to_string()<< " != " << std::endl;
   std::cout << (czas2 != czas) << std::endl; 

    return 0;
}
