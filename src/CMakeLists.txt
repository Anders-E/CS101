add_subdirectory(algorithms)
#add_subdirectory(data_structures)

# Main Executable TODO: Remove
add_executable (
	cs101
	cs101.c
	cs101.h
)
target_compile_features (
	cs101
	PRIVATE
	c_std_11
)
target_link_libraries (
	cs101
	PUBLIC
	sorting

	#PUBLIC
	#linkedlist

	#PUBLIC
	#binary_search_tree
)

