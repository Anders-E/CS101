cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.14)
    cmake_policy(
		VERSION
		${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}
	)
endif()

project (
	"CS 101"
	VERSION 0.1
    DESCRIPTION "A collection of computer science fundamentals including algorithms and datastructures"
	LANGUAGES CXX
)

add_library(
	sorting
	STATIC
	src/sorting.cpp
	src/sorting.h
)
target_include_directories(
	sorting
	PUBLIC
	include
)
target_compile_features(
	sorting
	PRIVATE
	cxx_std_17
)

add_executable(
	cs101
	src/CS101.cpp
	src/CS101.h
)
target_compile_features(
	cs101
	PRIVATE
	cxx_std_17
)
target_link_libraries(
	cs101
	PUBLIC
	sorting
)
