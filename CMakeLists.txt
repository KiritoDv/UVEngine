cmake_minimum_required(VERSION 3.16)
project(SpaceRPG)

set(CMAKE_CXX_STANDARD 20)

include_directories("src/include")

add_executable(SpaceRPG src/main.cpp src/engine/render.cpp src/engine/display.cpp src/engine/util/GFXUtil.cpp src/include/util/GFXUtil.h src/engine/camera.cpp src/include/engine/camera.h src/include/data/nwindow.h src/include/data/nmouse.h src/engine/texture/texture.cpp src/include/engine/texture/texture.h)

find_package(glfw3 CONFIG REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

target_link_libraries(SpaceRPG PRIVATE glm)
target_link_libraries(SpaceRPG PRIVATE GLEW::GLEW)
target_link_libraries(SpaceRPG PRIVATE GLUT::GLUT)
target_link_libraries(SpaceRPG PRIVATE glfw)
