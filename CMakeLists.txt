cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project (helloworlxd)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
if ($ENV{TRAVIS_BUILD_NUMBER})
set (PROJECT_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})
else()
set (PROJECT_VERSION_PATCH 0)
endif()

#Опции проекта
# option(BUILD_LIB_HELLO "Включить модульное тестирование" OFF)
# option(BUILD_LIB_TEST "Включить модульное тестирование" OFF)
option(TESTING_GTEST "Включить модульное тестирование" OFF)
option(COVERAGE_GTEST "Включить покрытие кода тестами" OFF)

configure_file(version.h.in version.h)

# set (CMAKE_CXX_COMPILER "/usr/bin/g++")
# set (CMAKE_CXX_COMPILER g++)

find_program(GCOVR_EXECUTABLE lcov)

add_library(LIB_PRINT STATIC lib/lib_print/lib_print.cpp)
add_library(LIB_HELLO STATIC lib/lib_hello/lib_hello.cpp)
add_library(LIB_BIG STATIC .)

target_link_libraries(LIB_BIG
LIB_PRINT
LIB_HELLO
)
#=====================================================
set(SOURCES 
main.cpp
)
set(HEADERS 
includes.h
errors.h
)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} LIB_BIG LIB_HELLO LIB_PRINT)
#=====================================================
# add_definitions(-DDEBUG)

# модульные гугл-тесты
if (TESTING_GTEST)
add_subdirectory(unit_test)
endif()