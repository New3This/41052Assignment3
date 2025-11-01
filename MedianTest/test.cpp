#include "DeterministicMedian.hpp"
#include <gtest/gtest.h>

TEST(DeterministicMedian, EmptyArray) {
	std::vector<double> array = {};
	EXPECT_FALSE(DeterministicMedian(array).has_value());
}

TEST(DeterministicMedianTests, SameMedianValuesEven) {
	std::vector<double> array = {0, 1, 5, 5, 6, 7};
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 5);
}

TEST(DeterministicMedianTests, SameMedianValuesOdd) {
	std::vector<double> array = {0, 1, 5, 5, 5, 6, 7};
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 5);
}

TEST(DeterministicMedianTests, MixedSameMedianValues) {
	std::vector<double> array = {7, 5.5, -1, 5.5, 2, 9};
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 5.5);
}

// Odd Arrayss

TEST(DeterministicMedianTests, SmallPositiveWholeArrayOdd) {
	std::vector<double> array = { 0,5,3,4,2 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 3);
}

TEST(DeterministicMedianTests, SmallPositiveArrayOdd) {
	std::vector<double> array = { 11.1, 2.3, 5.5, 10.1, 1.1 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 5.5);
}

TEST(DeterministicMedianTests, SmallNegativeWholeArrayOdd) {
	std::vector<double> array = { 0, -5, -3, -4, -2 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), -3);
}

TEST(DeterministicMedianTests, SmallNegativeArrayOdd) {
	std::vector<double> array = { -1.1, -3.3, -2.2, -3.1, -5.2, -2.1 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), -2.65);
}

TEST(DeterministicMedianTests, LargePositiveWholeArrayOdd) {
	std::vector<double> array = { 0,5,3,4,2,1,2,3,4,5,61,2,3423,1212,12,3242,565,6575,575834,343,232,121,43,435,2318,867231,1212 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 61);
}

TEST(DeterministicMedianTests, LargePositiveArrayOdd) {
	std::vector<double> array = { 0.2,5.5,3.1,4.2,2.2,1.5,2.7,3.9,4.9,5.2,61.21,2.12,3423.1,1212.2,12.2,3242.3,565.5 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 4.9);
}

TEST(DeterministicMedianTests, LargeNegativeWholeArrayOdd) {
	std::vector<double> array = { -2,-5,-3,-42,-22,-15,-27,39,-49,52,-61,-2,3423,1212,12,3242,-565 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), -3);
}

TEST(DeterministicMedianTests, LargeNegativeArrayOdd) {
	std::vector<double> array = { -0.2,-5.5,-3.1,-4.2,-2.2,-1.5,-2.7,3.9,-4.9,5.2,-61.21,-2.12,3423.1,1212.2,12.2,3242.3,-565.5 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), -2.12);
}

TEST(DeterministicMedianTests, mixedArrayOdd) {
	std::vector<double> array = { -1, 2.2, -2, 3.3, -5.1, 6, 2.2, 3.1,3, 52,1 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 2.2);
}

// Even Arrays

TEST(DeterministicMedianTests, SmallPositiveWholeArrayEven) {
	std::vector<double> array = { 0,5,3,4 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 3.5);
}

TEST(DeterministicMedianTests, SmallPositiveArrayEven) {
	std::vector<double> array = { 11.1, 2.3, 5.5, 10.1 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 7.8);
}

TEST(DeterministicMedianTests, SmallNegativeWholeArrayEven) {
	std::vector<double> array = { -5, -3, -4, -2 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), -3.5);
}

TEST(DeterministicMedianTests, SmallNegativeArrayEven) {
	std::vector<double> array = { -1.1, -3.3, -2.2, -3.1, -5.2 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), -3.1);
}

TEST(DeterministicMedianTests, LargePositiveWholeArrayEven) {
	std::vector<double> array = { 5,3,4,2,1,2,3,4,5,61,2,3423,1212,12,3242,565,6575,575834,343,232,121,43,435,2318,867231,1212 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 91);
}

TEST(DeterministicMedianTests, LargePositiveArrayEven) {
	std::vector<double> array = { 0.2,5.5,3.1,4.2,2.2,1.5,2.7,3.9,4.9,5.2,61.21,2.12,3423.1,1212.2,12.2,3242.3 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 4.55);
}

TEST(DeterministicMedianTests, LargeNegativeWholeArrayEven) {
	std::vector<double> array = { -2,-5,-3,-42,-22,-15,-27,39,-49,52,-61,-2,3423,1212,12,32 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), -2.5);
}

TEST(DeterministicMedianTests, LargeNegativeArrayEven) {
	std::vector<double> array = { -0.2,-5.5,-3.1,-4.2,-2.2,-1.5,-2.7,3.9,-4.9,5.2,-61.21,-2.12,3423.1,1212.2,12.2,3242.3 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), -1.81);
}

TEST(DeterministicMedianTests, mixedArrayEven) {
	std::vector<double> array = { -1, 2.2, -2, 3.3, -5.1, 6, 2.2, 3.1,3, 52 };
	ASSERT_DOUBLE_EQ(DeterministicMedian(array).value(), 2.6);
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}