find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
find_package(GMP REQUIRED)

add_executable(fair_warning main.cpp fair_warning.cpp)
target_link_libraries(fair_warning ${Boost_LIBRARIES} ${GMP_LIBRARIES})
