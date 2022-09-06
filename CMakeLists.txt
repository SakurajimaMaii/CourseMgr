cmake_minimum_required(VERSION 3.0)
project(CourseMgr)

set(CMAKE_CXX_STANDARD 23)

link_libraries(libeasyx.a)
add_executable(CourseMgr func.h func.cpp main.cpp picture.cpp)
