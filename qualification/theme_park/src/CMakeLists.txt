find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(theme_park main.cpp)
target_link_libraries(theme_park ${Boost_LIBRARIES})
