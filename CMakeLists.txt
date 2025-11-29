cmake_minimum_required(VERSION 3.10)
project(cvector VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

option(BUILD_SHARED_LIBS "Build shared libraries instead of static" OFF)

add_library(cvector src/cvector.c)
target_include_directories(cvector PUBLIC include)

add_executable(test tests/test_cvector.c)
target_link_libraries(test PRIVATE cvector)

