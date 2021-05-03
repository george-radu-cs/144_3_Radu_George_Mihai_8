cmake_minimum_required (VERSION 3.5)

project(144_3_Radu_George_Mihai_8 CXX)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set(SOURCES comenzi_pizza_enum.h exceptions.h functions.h functions.cpp)
  
add_library(
  ingredient
  ingredient.h
  ingredient.cpp)

add_library(
  pizza
  produs.h
  pizza.h
  pizza.cpp
  pizza_online.h
  pizza_online.cpp)

add_library(
  meniu
  meniu.h)

set_target_properties(meniu PROPERTIES LINKER_LANGUAGE CXX)

add_executable(144_3_Radu_George_Mihai_8 ${SOURCES} main.cpp)
target_link_libraries(144_3_Radu_George_Mihai_8 PRIVATE meniu pizza ingredient)

target_compile_features(144_3_Radu_George_Mihai_8 PRIVATE cxx_lambda_init_captures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
