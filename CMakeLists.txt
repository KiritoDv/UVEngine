cmake_minimum_required(VERSION 3.16)
project(UVEngine_SDL)

set(CMAKE_CXX_STANDARD 20)
include_directories("src/include")
file(COPY src/assets DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(UVEngine_SDL ${SOURCES} src/include/engine/util/EngineUtil.h)

find_package(glm CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(sdl2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

target_link_libraries(UVEngine_SDL PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(UVEngine_SDL PRIVATE SDL2::SDL2_image)
target_link_libraries(UVEngine_SDL PRIVATE nlohmann_json nlohmann_json::nlohmann_json)
target_link_libraries(UVEngine_SDL PRIVATE EnTT::EnTT)
target_link_libraries(UVEngine_SDL PRIVATE glm)
