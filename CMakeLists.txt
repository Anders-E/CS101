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
	LANGUAGES C CXX
)

# If this is the main project and not included as a subdirectory ...
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	# Target folder support for IDEs
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# Testing
    include(CTest)
	# Testing only available if this is the main app
	# Emergency override: CS101_BUILD_TESTING
	if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR CS101_BUILD_TESTING))
		enable_testing()

		include(ExternalProject)
		find_package(Git REQUIRED)

		ExternalProject_Add(
			doctest
			PREFIX ${CMAKE_BINARY_DIR}/extern
			GIT_REPOSITORY https://github.com/onqtam/doctest.git
			TIMEOUT 10
			UPDATE_COMMAND ${GIT_EXECUTABLE} pull
			CONFIGURE_COMMAND ""
			BUILD_COMMAND ""
			INSTALL_COMMAND ""
			LOG_DOWNLOAD ON
		)

		# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
		ExternalProject_Get_Property(doctest source_dir)
		set(DOCTEST_INCLUDE_DIR ${source_dir}/doctest CACHE INTERNAL "Path to include folder for doctest")

		add_subdirectory(test)
	endif ()
endif ()

# Variable for path to include folder
set(CS101_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Library Source Code
add_subdirectory(src)
