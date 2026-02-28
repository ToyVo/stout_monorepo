cmake_minimum_required(VERSION 3.15)
project(cpp_impl)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(cpp_impl main.cpp Customer.hpp)
target_link_libraries(cpp_impl Threads::Threads)