#include <algorithm>
#include <limits>
#include <boost/foreach.hpp>
#include <boost/math/common_factor.hpp>
#include "fair_warning.hpp"

int greatest_common_divisor(const std::vector<int>& numbers)
{
    std::vector<int>::const_iterator it = numbers.begin();
    int gcd = *it;
    for (it++; it != numbers.end(); it++)
        gcd = boost::math::gcd(gcd, *it);
    return gcd;
}

int calculate_apocalypse(std::vector<int> events)
{
    /*
     * This code is inspired by the submission of neal.wu, because I was
     * unable to come up with a reasonably fast solution myself.
     */
    std::sort(events.begin(), events.end());
    int min = events[0];
    for (std::vector<int>::iterator it = events.begin(); it != events.end();
         it++)
        *it -= min;
    int gcd = greatest_common_divisor(events);
    return (gcd - min % gcd) % gcd;
}
