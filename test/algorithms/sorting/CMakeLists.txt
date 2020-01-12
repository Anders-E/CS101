# Sorting Fixture
add_library (
	sorting_fixture
	STATIC
	sorting_fixture.cpp
)
target_compile_features (
	sorting_fixture
	PRIVATE
	cxx_std_17
)
target_link_libraries (
	sorting_fixture
	PUBLIC
	gtest
)

package_add_test_with_libraries(
	bubble_sort_test bubble_sort.cpp
	"sorting_fixture;sorting;test_util"
	${CMAKE_CURRENT_LIST_DIR}
)
