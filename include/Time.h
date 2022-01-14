#define s25030_TIME_H
#include <sstream>
#include <string>
namespace s25030 {
struct Time {
    int hour;
    int min;
    int sec;
    Time(int, int, int);
    auto to_string() const -> std::string;

    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;


    enum class Time_of_day {
        Morning,
        Afternoon,
        Evening,
        Night,
    };

    auto to_string(Time_of_day) -> std::string;
    auto time_of_day() const -> Time_of_day;
    auto operator+(Time const&) const -> Time;
    auto operator-(Time const&) const -> Time;
    auto operator<(Time const&) const -> bool;
    auto operator>(Time const&) const -> bool;
    auto operator==(Time const&) const -> bool;
    auto operator!=(Time const&) const -> bool;
    auto count_seconds() const -> uint64_t;
    auto count_minutes() const -> uint64_t;
    auto time_to_midnight() const -> Time;
};
}
