cmake_minimum_required (VERSION 3.5)

project(144_3_Radu_George_Mihai_8 VERSION 1.0)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

add_executable(144_3_Radu_George_Mihai_8 main.cpp)

target_compile_features(144_3_Radu_George_Mihai_8 PRIVATE cxx_lambda_init_captures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
