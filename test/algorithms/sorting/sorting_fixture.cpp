#include <random>

#include "gtest/gtest.h"

class SortingFixture : public ::testing::Test
{
  protected:
    void SetUp() override
    {
      // Set up RNG with fixed seed
      random_engine = std::default_random_engine(99);
    }

    //void TearDown() override
    //{
    //
    //}

    int desu;

  private:
    void randomize_array(int arr[], int n)
    {
      for (int i = 0; i < n; i++);
    }

    std::default_random_engine random_engine;
};
