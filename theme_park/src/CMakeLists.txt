find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(theme_park main.cpp)
target_link_libraries(theme_park ${Boost_LIBRARIES})
