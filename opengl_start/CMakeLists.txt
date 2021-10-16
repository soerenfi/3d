cmake_minimum_required(VERSION 3.2)

project(opengl-start)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

#dependencies
find_package(OpenGL REQUIRED)
find_library(COCOA_LIBRARY Cocoa REQUIRED)
find_library(IOKIT_LIBRARY IOKit REQUIRED)
find_library(COREVID_LIBRARY CoreVideo REQUIRED)
message(${COCOA_LIBRARY})
message(${IOKIT_LIBRARY})
message(${COREVID_LIBRARY})
find_package(GLEW 2.0 REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

include_directories(include)

set(SOURCE_FILES
src/main.cc)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/GLFW/include)
target_link_libraries(${PROJECT_NAME}
  ${OPENGL_LIBRARIES}
  ${COCOA_LIBRARY}
  ${IOKIT_LIBRARY}
  ${COREVID_LIBRARY}
  ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/GLFW/lib-x86_64/libglfw3.a
  GLEW::GLEW
  )
