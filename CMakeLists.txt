cmake_minimum_required(VERSION 3.0.0)
project(typelist)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-stdlib=libc++ -std=c++17")

add_executable(${PROJECT_NAME} usage_example.cpp)

add_subdirectory(lib)

set_target_properties(typelist_lib PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} typelist_lib)
