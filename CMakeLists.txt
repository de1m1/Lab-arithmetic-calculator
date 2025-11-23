cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(arithmetic-calculator)

set(CMAKE_BUILD_TYPE Debug)

include(cmake/function.cmake) 

add_subdirectory(src)
add_subdirectory(libs/List)
add_subdirectory(libs/Stack)
add_subdirectory(libs/TVector)


include_directories(
    ${CMAKE_SOURCE_DIR}/libs
    ${CMAKE_SOURCE_DIR}/libs/List
    ${CMAKE_SOURCE_DIR}/libs/Stack
    ${CMAKE_SOURCE_DIR}/libs/TVector
)

option(BTEST "build test?" ON)

if(BTEST)     
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory("third_party/gtest" EXCLUDE_FROM_ALL)
    enable_testing()
    add_subdirectory(tests)
endif()


