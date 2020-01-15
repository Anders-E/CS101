# CMake Version Required
cmake_minimum_required (VERSION 3.1...3.14)

if (${CMAKE_VERSION} VERSION_LESS 3.14)
	cmake_policy(
		VERSION
		${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}
	)
endif ()

# Project Information
project (
	"CS 101"
	VERSION 0.1
	DESCRIPTION "A collection of computer science fundamentals including algorithms and data structures"
	LANGUAGES CXX
)

# If this is the main project and not included as a subdirectory ...
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	# No compiler-specific extensions
	set(CMAKE_CXX_EXTENSIONS OFF)

	# Target folder support for IDEs
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# Testing
    #include(CTest)
	# Testing only available if this is the main app
	# Emergency override: CS101_BUILD_TESTING
	#if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
	#	enable_testing()
	#	include(GoogleTest)
	#	add_subdirectory(test)
	#ndif ()
endif ()

# Library Source Code
add_subdirectory(src)
