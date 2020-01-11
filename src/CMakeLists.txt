# Sorting
add_library (
	sorting
	STATIC
	algorithms/sorting.cpp
	algorithms/sorting.h
)
target_compile_features (
	sorting
	PRIVATE
	cxx_std_17
)

# Linked List
add_library (
	linkedlist
	STATIC
	data_structures/linkedlist.cpp
	data_structures/linkedlist.h
)
target_compile_features (
	linkedlist
	PRIVATE
	cxx_std_17
)

# Binary Search Tree
add_library (
	binary_search_tree
	STATIC
	data_structures/binary_search_tree.cpp
	data_structures/binary_search_tree.h
)
target_compile_features (
	binary_search_tree
	PRIVATE
	cxx_std_17
)

# Main Executable TODO: Remove
add_executable (
	cs101
	cs101.cpp
	cs101.h
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

	PUBLIC
	binary_search_tree
)