#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <rotate.hpp>

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    boost::multi_array<Player, 2> board(boost::extents[7][7]);
    BOOST_REQUIRE_EQUAL(NEITHER, determine_winner(board, 3));
}
