#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <boost/foreach.hpp>
#include <boost/math/common_factor.hpp>
#include "fair_warning.hpp"

bigint min;

bigint difference(bigint element)
{
    return abs(element - min);
}

bigint calculate_apocalypse(std::vector<bigint> events)
{
    std::sort(events.begin(), events.end());
    min = *events.begin();
    events.erase(events.begin());
    std::transform(events.begin(), events.end(), events.begin(), &difference);
    bigint gcd = std::accumulate(events.begin() + 1, events.end(),
                                 *events.begin(), &boost::math::gcd<bigint>);
    if (min % gcd == 0)
        return 0;
    return gcd - (min % gcd);
}
