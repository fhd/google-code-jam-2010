find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(rotate main.cpp)
target_link_libraries(rotate ${Boost_LIBRARIES})
