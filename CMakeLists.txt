cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project (helloworlxd)

set(CMAKE_PROJECT_HOMEPAGE_URL "shadoffarts.ru")
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
option(TESTING_GTEST "Включить модульное тестирование" ON)
option(COVERAGE_GTEST "Включить покрытие кода тестами" OFF)
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
configure_file(version.h.in version.h)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_BINARY_DIR}")
#=====================================================
# add_definitions(-DDEBUG)

set(CPACK_GENERATOR "DEB;TGZ")
set(CPACK_PACKAGE_CONTACT "shad@shad.ru")
set(CPACK_PACKAGE_DIRECTORY ${PROJECT_SOURCE_DIR}/packages)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "sir_Alexander")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Project_Hello by Alex for Otus")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
# set(CPACK_PACKAGE_INSTALL_DIRECTORY "/opt/mydir/")
if (CPACK_GENERATOR MATCHES "DEB")
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION /opt/mylib)
elseif (CPACK_GENERATOR MATCHES "DEB")
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
endif()
include(CPack)

# модульные гугл-тесты
if (TESTING_GTEST)
add_subdirectory(unit_test)
endif()

