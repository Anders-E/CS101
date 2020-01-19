# Sorting
add_library (
	sorting
	STATIC
	sorting/bubble_sort.c
	sorting/bucket_sort.c
	sorting/counting_sort.c
	sorting/heapsort.c
	sorting/insertion_sort.c
	sorting/merge_sort.c
	sorting/quicksort.c
	sorting/radix_sort.c
)
target_compile_features(sorting PRIVATE c_std_11)
if (UNIX)
	target_link_libraries(sorting m)
endif (UNIX)
target_include_directories (sorting PUBLIC "${CS101_INCLUDE_DIR}")
