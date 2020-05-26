cmake_minimum_required(VERSION 3.16)
project(SpaceRPG)

set(CMAKE_CXX_STANDARD 20)
include_directories("src/include")
file(COPY src/assets DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(SpaceRPG ${SOURCES})

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(SpaceRPG PRIVATE nlohmann_json nlohmann_json::nlohmann_json)
target_link_libraries(SpaceRPG PRIVATE EnTT::EnTT)
target_link_libraries(SpaceRPG PRIVATE glm)
target_link_libraries(SpaceRPG PRIVATE GLEW::GLEW)
target_link_libraries(SpaceRPG PRIVATE glfw)
