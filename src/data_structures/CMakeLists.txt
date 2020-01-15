# Linked List
add_library (
	linked_list
    STATIC
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
	"${CS101_INCLUDE_DIR}/data_structures"
)
