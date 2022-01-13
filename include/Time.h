struct Time
{
    int hour=1, minutes=0, sec=0;
    std::string to_string();
    auto next_hour()->void;
    auto next_minute()->void;
    auto next_second()->void;
    Time(int,int,int);
    
    auto time_of_day() const;
    
    auto operator+ (Time const&)  const -> Time;
    auto operator- (Time const&)  const -> Time;
    auto operator< (Time const&)  const -> bool;
    auto operator> (Time const&)  const -> bool;
    auto operator== (Time const&) const -> bool;
    auto operator!= (Time const&) const -> bool;
};

enum class Time_of_day {rano, dzien, wieczor, noc};

auto to_string(Time_of_day) -> std::string;
