set(SRC_DIR ../src)

include_directories(${SRC_DIR})
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(
  fair_warning_test
  fair_warning_test.cpp
  ${SRC_DIR}/fair_warning.cpp)
target_link_libraries(fair_warning_test ${Boost_LIBRARIES})
add_test(fair_warning fair_warning_test)
