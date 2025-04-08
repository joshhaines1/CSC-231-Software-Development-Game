cmake_minimum_required(VERSION 3.24)

project(game)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-g -Wall -Wextra -pedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(engine)
add_subdirectory(content)

add_executable(game main.cpp)
target_link_libraries(game PUBLIC engine entities)
