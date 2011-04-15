include_directories(../src)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(snapper_chain_test snapper_chain_test.cpp)
target_link_libraries(snapper_chain_test ${Boost_LIBRARIES})
add_test(snapper_chain snapper_chain_test)
