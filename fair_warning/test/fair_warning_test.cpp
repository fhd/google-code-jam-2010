#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <string>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <fair_warning.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_greatest_common_divisor)
{
    std::vector<int> numbers;
    numbers += 5, 10, 15;
    BOOST_REQUIRE_EQUAL(5, greatest_common_divisor(numbers));
}

void require_apocalypse_in(int expected, int event1, int event2, int event3)
{
    std::vector<int> events;
    events += event1, event2, event3;
    BOOST_REQUIRE_EQUAL(expected, calculate_apocalypse(events));
}

BOOST_AUTO_TEST_CASE(test_calculate_apocalypse)
{
    require_apocalypse_in(4000, 26000, 11000, 6000);
    require_apocalypse_in(4000000, 26000000, 11000000, 6000000);
}

BOOST_AUTO_TEST_CASE(test_calculate_apocalypse_not_possible)
{
    require_apocalypse_in(0, 1, 10, 11);
}

