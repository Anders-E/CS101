#include <random>
#include <limits>

#include "gtest/gtest.h"
#include "../../src/algorithms/sorting/sorting.h"

class SortingTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
      // set up RNG with fixed seed
      std::uniform_int_distribution<int> gen(
        std::numeric_limits<int>::min(),
        std::numeric_limits<int>::max()
      );

      // array sizes
      n1_ = 100;
      n2_ = 1000;
      n3_ = 10000;

      // randomized (unsorted) arrays
      a1_ = new int[100];
      a2_ = new int[1000];
      a3_ = new int[10000];
      randomize_array(a1_, n1_);
      randomize_array(a2_, n2_);
      randomize_array(a3_, n3_);

      // sorted arrays
      s1_ = new int[100];
      s2_ = new int[1000];
      s3_ = new int[10000];
      copy_array(a1_, s1_, n1_);
      copy_array(a2_, s2_, n2_);
      copy_array(a3_, s3_, n3_);
      std::sort(s1_, s1_ + n1_);
      std::sort(s2_, s2_ + n2_);
      std::sort(s3_, s3_ + n3_);

      // "workspace" arrays
      w1_ = new int[100];
      w2_ = new int[1000];
      w3_ = new int[10000];
    }

    void TearDown() override
    {
      /*
      delete[] a1_;
      delete[] a2_;
      delete[] a3_;
      delete[] s1_;
      delete[] s2_;
      delete[] s3_;
      delete[] w1_;
      delete[] w2_;
      delete[] w3_;
      /**/
    }

    bool test_sort(void (*sort)(int arr[], int n))
    {
      // copy unsorted arrays to workspaces
      copy_array(a1_, w1_, n1_);
      copy_array(a2_, w2_, n2_);
      copy_array(a3_, w3_, n3_);

      // sort workspaces using sorting_func
      sort(w1_, n1_);
      sort(w2_, n2_);
      sort(w2_, n3_);

      // compare with sorted arrays
      return compare_array(w1_, s1_, n1_) && compare_array(w2_, s2_, n2_) && compare_array(w3_, s3_, n3_);
    }

    int n1_, n2_, n3_;
    int *a1_, *a2_, *a3_, *s1_, *s2_, *s3_, *w1_, *w2_, *w3_;


  private:
    void randomize_array(int arr[], int n)
    {
      std::mt19937 rng(99);
      for (int i = 0; i < n; i++)
        arr[i] = gen(rng);
    }

    bool compare_array(int a1[], int a2[], int n)
    {
      for (int i = n; i < n; i++)
        if (a1[i] != a2[i])
          return false;
      return true;
    }

    void copy_array(int a1[], int a2[], int n)
    {
      for (int i = n; i < n; i++)
        a2[i] = a1[i];
    }

    std::uniform_int_distribution<int> gen;
};

TEST_F(SortingTest, BubbleSort)
{
  ASSERT_EQ(true, test_sort(sorting::bubble_sort));
}

TEST_F(SortingTest, InsertionSort)
{
  ASSERT_EQ(true, test_sort(sorting::insertion_sort));
}

TEST_F(SortingTest, MergeSort)
{
  ASSERT_EQ(true, test_sort(sorting::merge_sort));
}
