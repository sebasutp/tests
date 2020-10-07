cmake_minimum_required(VERSION 3.5)
project(PRIME_TESTS)
set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.58 COMPONENTS program_options)

add_executable(my_sieve my_sieve.cpp)

target_link_libraries(my_sieve ${Boost_LIBRARIES})
