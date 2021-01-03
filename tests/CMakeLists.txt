cmake_minimum_required(VERSION 3.15...3.19)

project(DesignPatterns VERSION 1.0
	DESCRIPTION "verify some design patterns and test them")

if(${CMAKE_VERSION} VERSION_LESS 3.19)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(SOURCES
	SourceMock.cpp ConcreteComponentTest.cpp ConcreteMediatorTest.cpp SecondConcreteComponentTest.cpp 
)

set(HEADERS
	IMediatorMock.hpp
)

add_executable(DesignPatternsTest ${SOURCES} ${HEADERS})

#include_directories(../headers/ConcreteComponent.hpp ../sources/ConcreteComponent.cpp)

target_link_libraries(DesignPatternsTest PUBLIC
	gtest gtest_main gmock_main componentLib
)

add_test(
	NAME DesignPatternsTest
	COMMAND DesignPatternsTest
)
