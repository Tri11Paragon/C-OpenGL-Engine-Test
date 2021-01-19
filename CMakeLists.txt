cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_subdirectory(glad)

set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB source_files "${source_dir}/*.cpp")
file(GLOB source_time "${source_dir}/b_time/*.cpp")
file(GLOB source_shaders "${source_dir}/shaders/*.cpp")
file(GLOB gl_data "${source_dir}/gldata/*.cpp")

add_executable(untitled ${source_files} ${source_time} ${source_shaders} ${gl_data})
target_link_libraries(untitled glfw)
target_link_libraries(untitled OpenGL::GL)
target_link_libraries(untitled glad)