#include <iostream>
#include <string>

namespace s25030 {
    struct Time {
        int hh;
        int mm;
        int ss;
        
        Time(int, int, int);
    
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;

    enum class Time_of_day {morning, day, evening, night};
    static auto to_string(Time_of_day const) -> std::string;
    auto time_of_day() const -> Time_of_day;
    auto to_string() const -> std::string;

    auto operator+ (Time const&) -> Time;
    auto operator- (Time const&) -> Time;
    auto operator< (Time const&) -> bool;
    auto operator> (Time const&) -> bool;
    auto operator== (Time const&) -> bool;
    auto operator!= (Time const&) -> bool;

    };
}
