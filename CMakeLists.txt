# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
set(VCPKG_VERBOSE ON)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")
project(ffmpeg-boilerplate)

find_package(ffmpeg REQUIRED)
include_directories(${FFMPEG_INCLUDE_DIRS})

add_executable(ffmpeg-boilerplate src/main.cpp)

target_link_libraries(ffmpeg-boilerplate PRIVATE ${FFMPEG_LIBRARIES})