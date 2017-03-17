#include <chrono>
#include <tuple>

namespace epsol {
namespace time {

/**
 * synonym for std::long::namespaces::now()
 */
template <typename Clock = std::chrono::system_clock>
typename Clock::time_point now() {
    return Clock::now();
}

namespace tags {
class year {};
class month {};
class day {};
class hour {};
class minute {};
class second {};
}

/**
 * generate a bunch of helper function to extract field of tm according to tags
 */
#define DEF_EXTRACT_IMPL(time, field)     \
    int extract_impl(tm* t, tags::time) { \
        return t->field;                  \
    }

DEF_EXTRACT_IMPL(day, tm_mday)
DEF_EXTRACT_IMPL(hour, tm_hour)
DEF_EXTRACT_IMPL(minute, tm_min)
DEF_EXTRACT_IMPL(second, tm_sec)

int extract_impl(tm* t, tags::year) {
    return t->tm_year + 1900;
}
int extract_impl(tm* t, tags::month) {
    return t->tm_mon + 1;
}

#undef EXTRACT_IMPL

template <typename... TimeTags, typename TimePoint>
auto extract(TimePoint tp) {
    time_t the_time = TimePoint::clock::to_time_t(tp);
    tm* tptr = localtime(&the_time);
    return std::make_tuple(extract_impl(tptr, TimeTags())...);
}

#define DEF_EXTRACT_SINGLE(time)                     \
    template <typename TimePoint>                    \
    int extract_##time(TimePoint tp) {               \
        return std::get<0>(extract<tags::time>(tp)); \
    }

DEF_EXTRACT_SINGLE(year)
DEF_EXTRACT_SINGLE(month)
DEF_EXTRACT_SINGLE(day)
DEF_EXTRACT_SINGLE(hour)
DEF_EXTRACT_SINGLE(minute)
DEF_EXTRACT_SINGLE(second)

#undef DEF_EXTRACT_SINGLE
}
}
auto tp = time::now<std::chrono::system_clock>();
class Time{
    int Hour, Minute, Second;
    public:
        Time();
        Time(int totalSeconds);
        int getHour();
        int getMinute();
        int getSecond(); 
    };
Time::Time()
{
	    auto tp = time::now<std::chrono::system_clock>();
        hour = time::extract_hour(tp);
        minute = time::extract_minute(tp);
        second = time::extract_second(tp);
}
Time(int totalSeconds)