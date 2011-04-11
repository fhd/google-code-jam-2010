find_package(Boost COMPONENTS system unit_test_framework REQUIRED)

add_executable(snapper main.cpp)

add_executable(snapper_test snapper_test.cpp)

target_link_libraries(snapper ${Boost_LIBRARIES})
target_link_libraries(snapper_test ${Boost_LIBRARIES})
add_test(snapper snapper_test)
