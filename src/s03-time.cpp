#include "Time.h"
#include <iostream>
#include <string>


auto s25030::Time::next_hour() -> void
{
    if (hour < 23) {
        ++hour;
    } else {
        hour = 0;
    }
}

auto s25030::Time::next_minute() -> void
{
    if (min < 59) {
        ++min;
    } else {
        min = 0;
        next_hour();
    }
}
auto s25030::Time::next_second() -> void
{
    if (sec < 59) {
        ++sec;
    } else {
        sec = 0;
        next_minute();
    }
}

s25030::Time::Time(int h, int m, int s) : hour{h}, min{m}, sec{s}
{}

auto s25030::Time::to_string() const -> std::string
{
    auto output = std::ostringstream{};

    if (hour < 10) {
        output << "0" << hour << ":";
    } else {
        output << hour << ":";
    }

    if (min < 10) {
        output << "0" << min << ":";
    } else {
        output << min << ":";
    }

    if (sec < 10) {
        output << "0" << sec;
    } else {
        output << sec;
    }

    return output.str();
}


auto s25030::Time::to_string(s25030::Time::Time_of_day const t) -> std::string
{
    switch (t) {
    case s25030::Time::Time_of_day::Morning:
        return "Morning";
    case s25030::Time::Time_of_day::Afternoon:
        return "Afternoon";
    case s25030::Time::Time_of_day::Evening:
        return "Evening";
    case s25030::Time::Time_of_day::Night:
        return "Night";
    default:
        return "What_time_of_day";
    }
}


auto s25030::Time::time_of_day() const -> s25030::Time::Time_of_day

{
    if (hour >= 5 && hour < 12)
        return s25030::Time::Time_of_day::Morning;

    else if (hour >= 12 && hour < 18)
        return s25030::Time::Time_of_day::Afternoon;

    else if (hour >= 18 && hour < 20)
        return s25030::Time::Time_of_day::Evening;

    else
        return s25030::Time::Time_of_day::Night;
}


auto s25030::Time::operator+(s25030::Time const& op) const -> s25030::Time
{
    int h = hour, m = min, s = sec;
    s = s + op.sec;
    m = m + op.min;
    h = h + op.hour;
    if (s > 59) {
        s = s - 60;
        m++;
    }
    if (m > 59) {
        m = m - 60;
        h++;
    }
    if (h > 23) {
        h = h - 24;
    }
    return Time(h, m, s);
}

auto s25030::Time::operator-(s25030::Time const& op) const -> s25030::Time
{
    int h = hour, m = min, s = sec;
    s = s - op.sec;
    m = m - op.min;
    h = h - op.hour;
    if (s < 0) {
        s = s + 60;
        m--;
    }
    if (m < 0) {
        m = m + 60;
        h--;
    }
    if (h < 0) {
        h = h + 24;
    }
    return Time(h, m, s);
}

auto s25030::Time::operator<(s25030::Time const& op) const -> bool
{
    int h = hour;
    int m = min;
    int s = sec;
    if (h < op.hour)
        return true;
    else if (m < op.min)
        return true;
    else if (s < op.sec)
        return true;
    else
        return false;
}

auto s25030::Time::operator>(s25030::Time const& op) const -> bool
{
    int h = hour;
    int m = min;
    int s = sec;
    if (h > op.hour)
        return true;
    else if (m > op.min)
        return true;
    else if (s > op.sec)
        return true;
    else
        return false;
}

auto s25030::Time::operator==(s25030::Time const& op) const -> bool
{
    int h = hour;
    int m = min;
    int s = sec;
    if (h == op.hour)
        return true;
    else if (m == op.min)
        return true;
    else if (s == op.sec)
        return true;
    else
        return false;
}

auto s25030::Time::operator!=(s25030::Time const& op) const -> bool
{
    int h = hour;
    int m = min;
    int s = sec;
    if (h != op.hour)
        return true;
    else if (m != op.min)
        return true;
    else if (s != op.sec)
        return true;
    else
        return false;
}
auto s25030::Time::count_seconds() const -> uint64_t
{
    int h = hour;
    int m = min;
    int s = sec;

    std::uint64_t c_sec = h * 3600 + m * 60 + s;
    return c_sec;
}


auto s25030::Time::count_minutes() const -> uint64_t
{
    int h = hour;
    int m = min;

    std::uint64_t c_min = h * 60 + m;
    return c_min;
}
auto s25030::Time::time_to_midnight() const -> s25030::Time
{
    s25030::Time tim_mid(0, 0, 0);
    tim_mid.sec  = 60 - sec;
    tim_mid.min  = 59 - min;
    tim_mid.hour = 23 - hour;

    return tim_mid;
}

auto main() -> int
{
    std::cout << "CZAS: ";
    auto time = s25030::Time(23, 59, 59);
    std::cout << time.to_string() << "\n";

    std::cout << "Next(hour,minute,second): ";
    time.next_minute();
    time.next_hour();
    time.next_second();
    std::cout << time.to_string() << "\n";

    std::cout << "Seconds: ";
    std::cout << time.count_seconds() << "\n";

    std::cout << "Minutes: ";
    std::cout << time.count_minutes() << "\n";

    std::cout << "Time to mindnight: ";
    std::cout << time.time_to_midnight().hour << ":";
    std::cout << time.time_to_midnight().min << ":";
    std::cout << time.time_to_midnight().sec << "\n";

    std::cout << "Time of Day: ";
    std::cout << time.to_string(time.time_of_day()) << "\n";
    
    std::cout << "Operatory: " << "\n";
    std::cout << "Dodawanie czasu\n";
    auto time_2 = time + s25030::Time(4, 0, 2);
    auto time_3 = time_2 - s25030::Time(5, 0, 59);
    std::cout << time_2.to_string() << "\n";
    std::cout << "Odjecie od czasu powyzej danego czasu\n";
    std::cout << time_3.to_string() << "\n";

    std::cout << "Porownywanie\n";
    auto time_4 = time > s25030::Time(5, 3, 5);
    std::cout << time.to_string() << " > " << s25030::Time(5, 3, 5).to_string() << "\n";
    if (time_4 == 1) {
        std::cout << "is true \n";
    } else {
        std::cout << "is false \n";
    }
    return 0;
}
