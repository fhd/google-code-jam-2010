#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <string>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <fair_warning.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_simple)
{
    std::vector<int> events;
    events += 26000, 11000, 6000;
    BOOST_REQUIRE_EQUAL(4000, calculate_apocalypse(events));
}


