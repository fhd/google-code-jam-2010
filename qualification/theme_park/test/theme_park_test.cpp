#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <theme_park.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_empty)
{
    std::queue<int> groups;
    BOOST_REQUIRE_EQUAL(0, profit_from(0, 0, groups));
}

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    std::queue<int> groups;
    groups += 1, 4, 2, 1;
    BOOST_REQUIRE_EQUAL(21, profit_from(4, 6, groups));
}

BOOST_AUTO_TEST_CASE(test_sample_2)
{
    std::queue<int> groups;
    groups += 1;
    BOOST_REQUIRE_EQUAL(100, profit_from(100, 10, groups));
}

BOOST_AUTO_TEST_CASE(test_sample_3)
{
    std::queue<int> groups;
    groups += 2, 4, 2, 3, 4, 2, 1, 2, 1, 3;
    BOOST_REQUIRE_EQUAL(20, profit_from(5, 5, groups));
}
