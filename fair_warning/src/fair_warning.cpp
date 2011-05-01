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
    int max_int = std::numeric_limits<int>::max(), apocalypse = 0,
        max_gcd = 0;
    for (int i = 0; i < max_int - max_gcd; i += max_gcd) {
        std::vector<int> events_plus_i(events);
        for (std::vector<int>::iterator it = events_plus_i.begin();
             it != events_plus_i.end(); it++)
            *it += i;

        int gcd = greatest_common_divisor(events_plus_i);
        if (gcd > max_gcd) {
            max_gcd = gcd;
            apocalypse = i;
        }
    }
    return apocalypse;
}
