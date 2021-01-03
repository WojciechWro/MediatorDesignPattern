cmake_minimum_required(VERSION 3.15...3.19)

project(DesignPatterns VERSION 1.0
	DESCRIPTION "verify some design patterns and test them")

if(${CMAKE_VERSION} VERSION_LESS 3.19)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(MediatorLib INTERFACE)
target_sources(MediatorLib INTERFACE ${PROJECT_SOURCE_DIR}/interface)
add_subdirectory(tests)

set(INCLUDE
	include/BaseComponent.hpp include/ConcreteComponent.hpp include/ConcreteMediator.hpp include/SecondConcreteComponent.hpp
)

set(SOURCES
	sources/BaseComponent.cpp sources/ConcreteComponent.cpp sources/ConcreteMediator.cpp sources/SecondConcreteComponent.cpp
)

add_library(componentLib ${HEADERS} ${SOURCES})

add_subdirectory(googletest-master)
enable_testing()

target_include_directories(componentLib INTERFACE interface/)
target_include_directories(componentLib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(runDesignPatterns Main.cpp)
target_link_libraries(runDesignPatterns componentLib gtest gtest_main gmock_main)
