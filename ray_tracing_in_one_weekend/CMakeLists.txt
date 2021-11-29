cmake_minimum_required(VERSION 3.2)

project(ray-tracing-weekend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

#dependencies
#find_package(OpenGL REQUIRED)

set(SOURCE_FILES
src/main.cc
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})