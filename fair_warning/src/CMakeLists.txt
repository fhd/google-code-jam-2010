find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(fair_warning main.cpp fair_warning.cpp)
target_link_libraries(fair_warning ${Boost_LIBRARIES})
