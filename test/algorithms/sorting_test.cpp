#include <gtest/gtest.h>
#include <algorithm>
#include <iterator>
#include <limits>
#include <random>
#include <vector>
extern "C" {
	#include <CS101/sorting.h>
}

// Vector sizes (both evens and odds)
const int N1 = 10;
const int N2 = N1 - 1;
const int N3 = 1000;
const int N4 = N3 - 1;
const int N5 = 10000;
const int N6 = N5 - 1;

class Sorting : public ::testing::Test
{
private:
	// RNG - Use default seed of 1
	std::default_random_engine rand_eng;
	std::uniform_int_distribution<int> uniform_dist = std::uniform_int_distribution<int>(
		0,
		std::numeric_limits<int>::max()
	);
	std::function<int()> random_int = [this](){ return uniform_dist(rand_eng); };

	// Sorted vectors - to be sorted using std::sort and used to verify correctness
	std::vector<std::vector<int>> sorted = {
		std::vector(N1, 0), std::vector(N2, 0), std::vector(N3, 0), std::vector(N4, 0), std::vector(N5, 0), std::vector(N6, 0)
	};
	// Workspace vectors - for functions being tested to use
	std::vector<std::vector<int>> workspaces = sorted;

	// Vectors with a smaller range of values for testing Counting Sort
	int k = 1000;
	std::vector<std::vector<int>> sorted_counting = {
		std::vector(N1, 0), std::vector(N2, 0), std::vector(N3, 0), std::vector(N4, 0), std::vector(N5, 0), std::vector(N6, 0)
	};
	std::vector<std::vector<int>> workspaces_counting = sorted_counting;
	std::uniform_int_distribution<int> uniform_dist_counting = std::uniform_int_distribution<int>(
		0,
		k - 1
	);
	std::function<int()> random_int_counting = [this](){ return uniform_dist_counting(rand_eng); };

protected:
	void SetUp() override
	{
		// Fill workspace vectors with random ints
		for (std::vector<int>& v : workspaces)
			std::generate(v.begin(), v.end(), random_int);

		// Make sorted copies of workspaces
		sorted = workspaces;
		for (std::vector<int>& v : sorted)
			std::sort(v.begin(), v.end(), std::less<int>());

		// Same for counting sort...
		for (std::vector<int>& v : workspaces_counting)
			std::generate(v.begin(), v.end(), random_int_counting);
		sorted_counting = workspaces_counting;
		for (std::vector<int>& v : sorted_counting)
			std::sort(v.begin(), v.end(), std::less<int>());

	}

public:
	void test_sort(std::function<void(int*, int*)> sort_func)
	{
		for (int i = 0; i < sorted.size() && i < workspaces.size(); i++) {
			auto w = workspaces[i];
			auto s = sorted[i];
			std::shuffle(w.begin(), w.end(), rand_eng);
			sort_func(w.data(), w.data() + w.size());
			EXPECT_EQ(w, s);
		}
	}

	void test_counting_sort()
	{
		for (int i = 0; i < sorted_counting.size() && i < workspaces_counting.size(); i++) {
			auto w = workspaces_counting[i];
			auto s = sorted_counting[i];
			std::shuffle(w.begin(), w.end(), rand_eng);
			CS101_counting_sort(w.data(), w.data() + w.size(), k);
			EXPECT_EQ(w, s);
		}
	}
};

TEST_F(Sorting, BubbleSort) {
	test_sort(CS101_bubble_sort);
}

TEST_F(Sorting, CountingSort) {
	test_counting_sort();
}

TEST_F(Sorting, Heapsort)
{
	test_sort(CS101_heapsort);
}

TEST_F(Sorting, MergeSort)
{
	test_sort(CS101_merge_sort);
}

TEST_F(Sorting, Quicksort)
{
	test_sort(CS101_quicksort);
}

TEST_F(Sorting, RadixSort)
{
	test_sort(CS101_radix_sort);
}
