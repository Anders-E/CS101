#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include <doctest.h>
#include <algorithm>

// array sizes
int n1 = 100;
int n2 = 1000;
int n3 = 10000;

// randomized (unsorted) arrays
int *a1 = new int[100];
int *a2 = new int[1000];
int *a3 = new int[10000];
// randomize_array(a1_, n1_);
// randomize_array(a2_, n2_);
// randomize_array(a3_, n3_);

// sorted arrays
int *s1 = new int[100];
int *s2 = new int[1000];
int *s3 = new int[10000];

std::sort(s1, s1 + n1);
std::sort(s2, s2 + n2);
std::sort(s3, s3 + n3);

// "workspace" arrays
int* w1 = new int[100];
int* w2 = new int[1000];
int* w3 = new int[10000];

TEST_CASE("testing bubble sort") {
	CHECK(1 == 1);
}

delete[] a1_;
delete[] a2_;
delete[] a3_;
delete[] s1_;
delete[] s2_;
delete[] s3_;
delete[] w1_;
delete[] w2_;
delete[] w3_;
