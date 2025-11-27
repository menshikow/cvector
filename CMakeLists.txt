cmake_minimum_required(VERSION 4.0)
project(cvector VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_library(cvector STATIC src/cvector.c)
target_include_directories(cvector PUBLIC include)

add_executable(test tests/test_cvector.c)
target_link_libraries(test PRIVATE cvector)
target_include_directories(test PRIVATE include)
