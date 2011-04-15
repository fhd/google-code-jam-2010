find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(snapper_chain main.cpp)
target_link_libraries(snapper_chain ${Boost_LIBRARIES})
