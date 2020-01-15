# Linked List
add_library (
	linked_list
    STATIC
    "${PROJECT_SOURCE_DIR}/include/data_structures/linked_list.h"
	linked_list.c
)
target_compile_features (
	linked_list
	PRIVATE
	c_std_11
)
target_include_directories (
	linked_list
	PUBLIC
	"${PROJECT_SOURCE_DIR}/include/data_structures"
)
