# Sorting
add_library (
	sorting
	STATIC
	sorting/bubble_sort.cpp
	sorting/bubble_sort.h
	sorting/insertion_sort.cpp
	sorting/insertion_sort.h
	sorting/merge_sort.cpp
	sorting/merge_sort.h
)
target_compile_features (
	sorting
	PRIVATE
	cxx_std_17
)
