cmake_minimum_required(VERSION 3.2)

project(opengl-start)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

#dependencies
find_package(OpenGL REQUIRED)

if(APPLE)
  find_library(COCOA_LIBRARY Cocoa REQUIRED)
  find_library(IOKIT_LIBRARY IOKit REQUIRED)
  find_library(COREVID_LIBRARY CoreVideo REQUIRED)
  message(${COCOA_LIBRARY})
  message(${IOKIT_LIBRARY})
  message(${COREVID_LIBRARY})
endif()

if(UNIX)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/glfw)
endif()


find_package(GLEW 2.0 REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

include_directories(include)

set(SOURCE_FILES
src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/GLFW/include)
target_link_libraries(${PROJECT_NAME}
  ${OPENGL_LIBRARIES}

  GLEW::GLEW
  glfw
  )
  
if(APPLE)
target_link_libraries(${PROJECT_NAME}
  ${COCOA_LIBRARY}
  ${IOKIT_LIBRARY}
  ${COREVID_LIBRARY}
)
endif()