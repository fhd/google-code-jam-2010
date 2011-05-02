#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <string>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <fair_warning.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_greatest_common_divisor)
{
    std::vector<bigint> numbers;
    numbers += 5, 10, 15;
    BOOST_REQUIRE_EQUAL("5", greatest_common_divisor(numbers).get_str());
}

BOOST_AUTO_TEST_CASE(test_calculate_apocalypse)
{
    std::vector<bigint> events;
    events += 26000, 11000, 6000;
    BOOST_REQUIRE_EQUAL("4000", calculate_apocalypse(events).get_str());
    events.clear();
    events += 26000000, 11000000, 6000000;
    BOOST_REQUIRE_EQUAL("4000000", calculate_apocalypse(events).get_str());
}

BOOST_AUTO_TEST_CASE(test_calculate_apocalypse_not_possible)
{
    std::vector<bigint> events;
    events += 1, 10, 11;
    BOOST_REQUIRE_EQUAL("0", calculate_apocalypse(events).get_str());
}

BOOST_AUTO_TEST_CASE(test_calculate_bigint_apocalypse)
{
    std::vector<bigint> events;
    events += bigint("800000000000000000001"),
        bigint("900000000000000000001");
    BOOST_REQUIRE_EQUAL("99999999999999999999",
                        calculate_apocalypse(events).get_str());
}
