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
	LANGUAGES C
)

# If this is the main project and not included as a subdirectory ...
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
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
	#endif ()
endif ()

# Variable for path to include folder
set(CS101_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Library Source Code
add_subdirectory(src)
