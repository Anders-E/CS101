#include <gtest/gtest.h>
#include <random>
#include <limits>
#include <CS101/sorting.h>

class SortingTest : public ::testing::Test
{
protected:
	void SetUp() override
	{

	}

	void TearDown() override
	{

	}
};

TEST(TestTest, 0is0) {
	EXPECT_EQ(0, 0);
}

TEST(TestTest, 1is1) {
	EXPECT_EQ(1, 1);
}
