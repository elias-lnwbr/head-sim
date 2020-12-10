cmake_minimum_required(VERSION 3.13)

# set the project name
project(HeadmasterSimulator
        DESCRIPTION "Simulez un headmaster."
        HOMEPAGE_URL "https://git.unistra.fr/barre-oblique-v3/t432_sab20_t3_b"
        LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_NAME "head-sim")
file(GLOB SOURCES src/*/*.cpp include/imgui/*.*)

if(UNIX)
  find_package(SFML COMPONENTS graphics window system REQUIRED)
endif()
include_directories(include)
link_directories(src include/imgui)
add_executable(${EXECUTABLE_NAME} src/Main.cpp ${SOURCES})
if(UNIX)
  target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system GL)
elseif(WIN32)
  target_link_libraries(${EXECUTABLE_NAME} "lib/sfml-graphics-d" "lib/sfml-window-d" "lib/sfml-system-d" opengl32)
endif()

file(COPY resources DESTINATION .)
