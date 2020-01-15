# Sorting
add_library (
	sorting
	STATIC
	sorting/bubble_sort.c
	sorting/insertion_sort.c
	sorting/merge_sort.c
)
target_compile_features (
	sorting
	PRIVATE
	c_std_11
)
target_include_directories (
	sorting
	PUBLIC
	"${CS101_INCLUDE_DIR}/algorithms"
)
