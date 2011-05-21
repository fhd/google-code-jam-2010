find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(rotate main.cpp)
target_link_libraries(rotate ${Boost_LIBRARIES})
