cmake_minimum_required(VERSION 3.15) 

project(temp_shit)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-stdlib=libc++ -std=c++17")

set(SOURCE_EXE temp.cpp)
#set(SOURCE_LIB typelist.hpp)

#add_library(inc STATIC ${SOURCE_LIB})

add_executable(temp ${SOURCE_EXE})

#target_link_libraries(temp inc)
