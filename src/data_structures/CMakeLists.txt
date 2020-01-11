# Linked List
add_library (
	linkedlist
	STATIC
	linkedlist.cpp
	linkedlist.h
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
	binary_search_tree.cpp
	binary_search_tree.h
)
target_compile_features (
	binary_search_tree
	PRIVATE
	cxx_std_17
)
