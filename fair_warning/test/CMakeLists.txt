include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(fair_warning_test fair_warning_test.cpp)
target_link_libraries(fair_warning_test ${Boost_LIBRARIES})
add_test(fair_warning fair_warning_test)
