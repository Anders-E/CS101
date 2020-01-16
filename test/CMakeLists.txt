add_executable(
	sorting_test
	algorithms/sorting_test.cpp
)
target_compile_features (
	sorting_test
	PRIVATE
	cxx_std_11
)
set_source_files_properties(algorithms/sorting_test.cpp PROPERTIES LANGUAGE CXX)
target_include_directories(sorting_test PUBLIC ${DOCTEST_INCLUDE_DIR})
#doctest_discover_tests(sorting_test)
