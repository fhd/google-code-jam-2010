#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <string>
#include <boost/test/unit_test.hpp>
#include "snapper.hpp"

void require_light_bulb_on(int snapper, int snaps, bool on)
{
   BOOST_REQUIRE_MESSAGE(is_light_bulb_on(snapper, snaps) == on,
                         "Light bulb should be " << (on ? "ON" : "OFF")
                         << " for '" << snapper << " " << snaps << "'");
}

BOOST_AUTO_TEST_CASE(test_simple)
{
   require_light_bulb_on(1, 1, true);
   require_light_bulb_on(2, 3, true);
   require_light_bulb_on(3, 7, true);
   require_light_bulb_on(4, 15, true);
}

BOOST_AUTO_TEST_CASE(test_multiple)
{
   require_light_bulb_on(4, 31, true);
   require_light_bulb_on(4, 47, true);
}


