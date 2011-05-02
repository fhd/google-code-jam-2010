#include <algorithm>
#include <limits>
#include <boost/foreach.hpp>
#include <boost/math/common_factor.hpp>
#include "fair_warning.hpp"

bigint greatest_common_divisor(const std::vector<bigint>& numbers)
{
    std::vector<bigint>::const_iterator it = numbers.begin();
    bigint gcd = *it;
    for (it++; it != numbers.end(); it++)
        gcd = boost::math::gcd(gcd, *it);
    return gcd;
}

bigint calculate_apocalypse(std::vector<bigint> events)
{
    /*
     * This code is inspired by the submission of neal.wu, because I was
     * unable to come up with a reasonably fast solution myself.
     */
    std::sort(events.begin(), events.end());
    bigint min = events[0];
    for (std::vector<bigint>::iterator it = events.begin(); it != events.end();
         it++)
        *it -= min;
    bigint gcd = greatest_common_divisor(events);
    return (gcd - min % gcd) % gcd;
}
