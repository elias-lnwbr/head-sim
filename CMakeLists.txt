cmake_minimum_required(VERSION 3.10)

# set the project name
project(HeadmasterSimulator VERSION 1.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_NAME "head-sim")

include_directories(BEFORE include)

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(${EXECUTABLE_NAME} src/Main.cpp)
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system GL)
