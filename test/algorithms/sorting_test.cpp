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
		std::numeric_limits<int>::max(),
		std::numeric_limits<int>::min()
	);
	std::function<int()> random_int = [this](){ return uniform_dist(rand_eng); };

	// Sorted vectors - to be sorted using std::sort and used to verify correctness
	std::vector<std::vector<int>> sorted = std::vector{
		std::vector(N1, 0), std::vector(N2, 0), std::vector(N3, 0), std::vector(N4, 0), std::vector(N5, 0), std::vector(N6, 0)
	};
	// Workspace vectors - for functions being tested to use
	std::vector<std::vector<int>> workspaces = sorted;

protected:
	void SetUp() override
	{
		// Fill sorted vectors with random ints
		for (std::vector<int>& v : sorted)
			std::generate(v.begin(), v.end(), random_int);

		// Copy not yet sorted vectors into corresponding workspace vectors
		for (int i = 0; i < sorted.size() && i < workspaces.size(); i++)
			workspaces[i] = sorted[i];

		// Sort (not yet) sorted vectors
		for (std::vector<int>& v : sorted)
			std::sort(v.begin(), v.end(), std::less<int>());
	}

public:
	void test_sort(std::function<void(int*, int*)> sort_func)
	{
		for (int i = 0; i < sorted.size() && i < workspaces.size(); i++) {
			auto w = workspaces[i];
			auto s = sorted[i];
			std::random_shuffle(w.begin(), w.end());
			sort_func(w.data(), w.data() + w.size());
			EXPECT_EQ(w, s);
		}
	}
};

TEST_F(Sorting, BubbleSort) {
	test_sort(bubble_sort);
}

// TODO: enable test when bucket_sort implemented
TEST_F(Sorting, DISABLED_BucketSort)
{
	test_sort(bucket_sort);
}

TEST_F(Sorting, Heapsort)
{
	test_sort(heapsort);
}

TEST_F(Sorting, MergeSort)
{
	test_sort(merge_sort);
}

TEST_F(Sorting, Quicksort)
{
	test_sort(quicksort);
}

TEST_F(Sorting, RadixSort10)
{
	test_sort([](int* first, int* last) { radix_sort(first, last, 10); });
}
