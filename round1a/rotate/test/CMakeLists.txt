include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(rotate_test rotate_test.cpp)
target_link_libraries(rotate_test ${Boost_LIBRARIES})
add_test(rotate rotate_test)
