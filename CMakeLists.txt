### CMAKE VERSION ###
	cmake_minimum_required (VERSION 3.1...3.14)

	if (${CMAKE_VERSION} VERSION_LESS 3.14)
		cmake_policy(
			VERSION
			${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}
		)
	endif ()

### PROJECT INFORMATION ###
	project (
		"CS 101"
		VERSION 0.1
		DESCRIPTION "A collection of computer science fundamentals including algorithms and data structures"
		LANGUAGES CXX
	)

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)

# Find packages go here.

# You should usually split this into folders, but this is a simple example

### SORTING LIBRARY ###
	add_library (
		sorting
		STATIC
		src/algorithms/sorting.cpp
		src/algorithms/sorting.h
	)
	target_compile_features (
		sorting
		PRIVATE
		cxx_std_17
	)

### LINKED LIST LIBRARY ###
	add_library (
		linkedlist
		STATIC
		src/data_structures/linkedlist.cpp
		src/data_structures/linkedlist.h
	)
	target_compile_features (
		linkedlist
		PRIVATE
		cxx_std_17
	)

### MAIN EXECUTABLE ###
	add_executable (
		cs101
		src/cs101.cpp
		src/cs101.h
	)
	target_compile_features (
		cs101
		PRIVATE
		cxx_std_17
	)
	target_link_libraries (
		cs101
		PUBLIC
		sorting

		PUBLIC
		linkedlist
	)
