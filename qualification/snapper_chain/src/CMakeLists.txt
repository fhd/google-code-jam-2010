find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(snapper_chain main.cpp)
target_link_libraries(snapper_chain ${Boost_LIBRARIES})
