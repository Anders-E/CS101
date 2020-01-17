add_subdirectory(algorithms)
add_subdirectory(data_structures)

# Main Executable TODO: Remove
add_executable (
	cs101
	cs101.c
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

	PUBLIC
	linked_list

	#PUBLIC
	#binary_search_tree
)
target_include_directories (
	sorting
	PUBLIC
	"${PROJECT_SOURCE_DIR}/include/algorithms"
	"${PROJECT_SOURCE_DIR}/include/data_structures"
)

