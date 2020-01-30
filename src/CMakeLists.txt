add_subdirectory(algorithms)
add_subdirectory(data_structures)

# Main Executable TODO: Remove
add_executable (cs101 cs101.c)
target_compile_features(cs101 PRIVATE c_std_11)
target_link_libraries(
	cs101
	PUBLIC
	sorting

	PUBLIC
	linked_list
	
	PUBLIC
	heap

	PUBLIC
	util

	PUBLIC
	stack

	PUBLIC
	queue
)
target_include_directories(cs101 PUBLIC "${CS101_INCLUDE_DIR}")

# Utility functions
add_library(util STATIC util.c)
target_compile_features(util PRIVATE c_std_11)
target_include_directories(util PUBLIC "${CS101_INCLUDE_DIR}")
