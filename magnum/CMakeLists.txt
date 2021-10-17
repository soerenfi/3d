cmake_minimum_required(VERSION 3.2)

project(magnum)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")


#find magnum
add_subdirectory(thirdparty/corrade EXCLUDE_FROM_ALL) # so only things you use are built

#dependencies
find_package(OpenGL REQUIRED)

if(UNIX)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/glfw)
endif()

set(WITH_SDL2APPLICATION OFF CACHE BOOL "" FORCE)
set(WITH_GLFWAPPLICATION ON FORCE)
add_subdirectory(thirdparty/magnum EXCLUDE_FROM_ALL)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

include_directories(include)

set(SOURCE_FILES
  src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/GLFW/include
)

set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    Corrade::Main
    Magnum::GlfwApplication
    Magnum::GL
    Magnum::Magnum
    Magnum::MeshTools
    Magnum::Primitives
    Magnum::Shaders    )
