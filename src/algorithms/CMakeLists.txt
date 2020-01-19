# Sorting
add_library (
	sorting
	STATIC
	sorting/counting_sort.c
	sorting/bubble_sort.c
	sorting/heapsort.c
	sorting/insertion_sort.c
	sorting/merge_sort.c
	sorting/quicksort.c
	sorting/radix_sort.c
)
target_compile_features(sorting PRIVATE c_std_11)
target_link_libraries(sorting m)
target_include_directories (sorting PUBLIC "${CS101_INCLUDE_DIR}")
