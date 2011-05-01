#include <algorithm>
#include <limits>
#include <boost/foreach.hpp>
#include <boost/math/common_factor.hpp>
#include "fair_warning.hpp"

int greatest_common_divisor(std::vector<int> numbers)
{
    std::vector<int>::iterator it = numbers.begin();
    int gcd = *it;
    for (it++; it != numbers.end() && gcd > 1; it++)
        gcd = boost::math::gcd(gcd, *it);
    return gcd;
}

int calculate_apocalypse(std::vector<int> events)
{
    const int max_event = *std::max_element(events.begin(), events.end());
    int apocalypse = 0, max_gcd = 0;
    for (int i = 0;;) {
        std::vector<int> events_plus_i(events);
        for (std::vector<int>::iterator it = events_plus_i.begin();
             it != events_plus_i.end(); it++)
            *it += i;

        int gcd = greatest_common_divisor(events_plus_i);
        if (gcd > max_gcd) {
            max_gcd = gcd;
            apocalypse = i;
        }

        if (i > max_event * 10)
            break;

        i += max_gcd;
    }
    return apocalypse;
}
