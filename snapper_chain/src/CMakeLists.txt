find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(snapper main.cpp)
target_link_libraries(snapper ${Boost_LIBRARIES})
