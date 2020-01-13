# Sorting
add_library (
	sorting
	STATIC
	sorting/sorting.h
	sorting/bubble_sort.cpp
	sorting/insertion_sort.cpp
	sorting/merge_sort.cpp
)
target_compile_features (
	sorting
	PRIVATE
	cxx_std_17
)
