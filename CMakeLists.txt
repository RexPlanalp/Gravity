cmake_minimum_required(VERSION 3.15...3.29)

project(Gravity VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(grav src/main.cpp src/Box.cpp src/Particle.cpp src/Universe.cpp src/Vec3.cpp)

target_include_directories(grav PRIVATE ${CMAKE_SOURCE_DIR}/include)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Configuring for Debug build")
    target_compile_options(grav PRIVATE
        -g
        -O0
        -Wall -Wextra -pedantic
)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Configuring for Release build")
    target_compile_options(grav PRIVATE  
        -O3
        -DNDEBUG 
        -march=native
        -flto
    )
else()
    message(WARNING "Unknown build type: ${CMAKE_BUILD_TYPE}. Defaulting to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()



