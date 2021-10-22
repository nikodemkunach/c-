#include <iostream>
#include <string>
#include "Time.h"

s25030::Time::Time(int hh, int mm, int ss) : hh{hh}, mm{mm}, ss{ss}
{}

auto s25030::Time::to_string(const Time_of_day time_of_day) -> std::string
{
    switch (time_of_day) {
        case Time_of_day::morning:
            return "Morning\n";
        case Time_of_day::day:
            return "Day\n";
        case Time_of_day::evening:
            return "Evening\n";
        case Time_of_day::night:
            return "Night\n";
        break;
    }
}


auto s25030::Time::time_of_day() const -> Time::Time_of_day
{
    if (hh <= 6) {
        return Time_of_day::night;
    } else if (hh <= 10) {
        return Time_of_day::morning;
    } else if (hh <= 17) {
        return Time_of_day::evening;
    } else if (hh <= 21) {
        return Time_of_day::night;
    }
}

auto s25030::Time::next_hour() -> void
{
    hh++;
    if (hh >= 24) {
        hh = 0;
    }
}

auto s25030::Time::next_minute() -> void
{
    mm++;
    if (mm > 59) {
        mm = 0;
        next_hour();
        if (hh >= 24) {
            hh = 0;
        }    
    }
}

auto s25030::Time::next_second() -> void
{
    ss++;
    if (ss > 59) {
        ss = 0;
        next_minute();
        if (mm > 59) {
            mm = 0 ;
            next_hour();
            if (hh >= 24) {
                hh = 0;
            }
        }
    }
}

auto s25030::Time::operator+ (Time const& time) -> Time
{
    for (int i = 0; i < time.hh; i++)
    {
        next_hour();
    }
    
    for (int i = 0; i < time.mm; i++)
    {
        next_minute();
    }

    for (int i = 0; i < time.ss; i++)
    {
        next_second();
    }

    return time;
}

auto s25030::Time::operator- (Time const& time) -> Time
{
    auto hh_minus = hh - time.hh;
    auto mm_minus = mm - time.hh;
    auto ss_minus = ss - time.hh;

    if (hh_minus < 0) {
        hh = 24 + hh_minus;
    }
    if (mm_minus < 0) {
        hh_minus = hh_minus - 1;
        mm = 60 + mm_minus;
    }
    if (ss_minus < 0) {
        mm_minus = mm_minus - 1;
        ss = 60 + ss_minus;
    }
    
    return time;
}

auto s25030::Time::operator< (Time const& time) -> bool
{
    if (hh == time.hh & mm == time.mm) {
        return ss < time.ss;
    }
    if (hh == time.hh) {
        return mm < time.mm;
    }
    
    return ss < time.ss;
}


auto main() -> int
{
    std::cout << "Time::to_string(): " << "\n";
    s25030::Time time = s25030::Time { 23, 59, 59 };
    std::cout << time.to_string() << "\n";

    std::cout << "next_hour: " << "\n";
    time = s25030::Time {23, 59, 59 };
    time.next_hour();
    std::cout << time.to_string() << "\n";

    std::cout << "next_minute: " << "\n";
    time = s25030::Time {23, 59, 59};
    time.next_minute();
    std::cout << time.to_string() << "\n";

    std::cout << "next_second: " << "\n";
    time = s25030::Time {23, 59, 59};
    time.next_second();
    std::cout << time.to_string() << "\n";

    std::cout << "time_of_day: " << "\n";
    time = s25030::Time {23, 59, 59 };
    std::cout << s25030::Time::to_string(time.time_of_day()) << "\n";

    std::cout << "operator+: " << "\n";
    auto a = s25030::Time { 23, 59, 59 };
    auto b = s25030::Time {  0,  0,  1 };
    std::cout << (a + b).to_string() << "\n";

    auto a = s25030::Time{  3, 59, 59 };
    auto b = s25030::Time{  4,  0,  0 };
    std::cout << (a - b).to_string() << "\n;"

    auto a = s25030::Time{ 23, 59, 59 };
    auto b = s25030::Time{  0,  0,  1 };
    if (a > b) {
        std::cout << a.to_string() << " > " << b.to_string() << "\n";
    } else {
        std::cout << a.to_string() << " ? " << b.to_string() << "\n";
    }
    

    return 0;
    }
