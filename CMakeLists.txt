cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_subdirectory(glad)
add_subdirectory(glm)

set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB_RECURSE source_files "${source_dir}/*.cpp")

add_executable(untitled ${source_files})
target_link_libraries(untitled glfw)
target_link_libraries(untitled OpenGL::GL)
target_link_libraries(untitled glad)
target_link_libraries(untitled glm)