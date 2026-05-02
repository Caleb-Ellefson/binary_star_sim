cmake_minimum_required(VERSION 3.10)
project(BinaryStarSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.3 REQUIRED)
# Find the system's OpenGL
find_package(OpenGL REQUIRED)

set(SOURCE_FILES 
    src/main.cpp 
    src/glad.c
)

add_executable(opengl_app ${SOURCE_FILES})

# This replaces your -I flags
target_include_directories(opengl_app PRIVATE 
    include 
    /usr/local/include
)

if(WIN32)
    set(OPENGL_LIBRARIES opengl32.lib)
else()
    set(OPENGL_LIBRARIES GL)
endif()

target_link_libraries(opengl_app PRIVATE 
    glfw 
    ${OPENGL_LIBRARIES}
    ${CMAKE_DL_LIBS}
)