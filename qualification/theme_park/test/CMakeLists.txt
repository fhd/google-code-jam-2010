include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(theme_park_test theme_park_test.cpp)
target_link_libraries(theme_park_test ${Boost_LIBRARIES})
add_test(theme_park theme_park_test)
