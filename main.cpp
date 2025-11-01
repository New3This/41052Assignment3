#include "randomMedian.hpp"
#include "gtest/gtest.h"


// Odd Arrays
TEST(RandomisedMedianTests, emptySet) {
	std::vector<int> input{};
	int medianIndex = 0;
	double foundMedian = findingMedian<int>(input, medianIndex);
	EXPECT_EQ(foundMedian, medianIndex);
}

TEST(RandomisedMedianTests, sizeOne) {
	std::vector<int> input{1};

	double foundMedian = findingMedian<int>(input, 0);

	EXPECT_EQ(foundMedian, 1);
}

TEST(RandomisedMedianTests, unorderedOddThree) {
	std::vector<int> input{9, 2, 15};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}

TEST(RandomisedMedianTests, identicalNumbers) {
	std::vector<int> input{1, 1, 1, 1, 1, 1};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}


TEST(RandomisedMedianTests, unorderedOddFive) {
	std::vector<int> input{4, 0, 3, 2, 1};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}


TEST(RandomisedMedianTests, negativeNumbers) {
	std::vector<int> input{-8, -10, -5, -20, -16};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}


TEST(RandomisedMedianTests, negativeAndPositiveNumbers) {
	std::vector<int> input{20, -1, -9, 11, 2, 3, -99};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}

TEST(RandomisedMedianTests, medianIndexAtEnd) {
	std::vector<int> input{1, 2, 3, 5, 6, 7, 4};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}


TEST(RandomisedMedianTests, medianIndexAtStart) {
	std::vector<int> input{4, 1, 2, 3, 5, 6, 7};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}


TEST(RandomisedMedianTests, floatSize3) {
	std::vector<float> input{2.567, 3.43, 1.8910,};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<float>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}

TEST(RandomisedMedianTests, doubleSize3) {
	std::vector<double> input{4.56789, 3.221434,15.2121334 };

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}

TEST(RandomisedMedianTests, allZeros) {
	std::vector<double> input{0, 0, 0, 0, 0, 0, 0, 0, 0};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}



TEST(RandomisedMedianTests, size10000) {
	std::vector<int> input{};
	for (int i = 0; i < 1000; ++i) {
		input.push_back(i);
	}
	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}

TEST(RandomisedMedianTests, size1001Random) {
	std::vector<int> input{};
	for (int i = 0; i < 1001; ++i) {
		input.push_back(rand());
	}
	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian<int>(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	EXPECT_EQ(foundMedian, median);
}

// Even Arrays

TEST(RandomisedMedianTests, sizeTwo) {
	std::vector<double> input{15, 18};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	double foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	double median1 = input.at(medianIndex);
	double median2 = input.at(medianIndex + 1);
	double trueMedian = (median1 + median2) / 2;

	EXPECT_EQ(foundMedian, trueMedian);
}

TEST(RandomisedMedianTests, negativeNumbersEven) {
	std::vector<double> input{-3, -5, -10, -2, -2, -2112, -23, -2};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	double foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	double median1 = input.at(medianIndex);
	double median2 = input.at(medianIndex + 1);
	double trueMedian = (median1 + median2) / 2;

	EXPECT_EQ(foundMedian, trueMedian);
}

TEST(RandomisedMedianTests, negativeAndPostiveEven) {
	std::vector<double> input{-9, 45, 99, -12, -121, -1, 1, 0, -21, 67};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	double foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	double median1 = input.at(medianIndex);
	double median2 = input.at(medianIndex + 1);
	double trueMedian = (median1 + median2) / 2;

	EXPECT_EQ(foundMedian, trueMedian);
}

TEST(RandomisedMedianTests, firstMiddleAtStart) {
	std::vector<double> input{5, 1, 2, 3, 4, 10, 6, 7, 8, 9};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	double foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	double median1 = input.at(medianIndex);
	double median2 = input.at(medianIndex + 1);
	double trueMedian = (median1 + median2) / 2;

	EXPECT_EQ(foundMedian, trueMedian);
}

TEST(RandomisedMedianTests, firstMiddleAtEndEven) {
	std::vector<double> input{ 1, 2, 3, 4, 10, 6, 7, 8, 9, 5 };

	int medianIndex = ((input.size() + 1) / 2) - 1;

	double foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	double median1 = input.at(medianIndex);
	double median2 = input.at(medianIndex + 1);
	double trueMedian = (median1 + median2) / 2;

	EXPECT_EQ(foundMedian, trueMedian);
}

TEST(RandomisedMedianTests, tenZeros) {
	std::vector<double> input{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	double foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	double median1 = input.at(medianIndex);
	double median2 = input.at(medianIndex + 1);
	double trueMedian = (median1 + median2) / 2;

	EXPECT_EQ(foundMedian, trueMedian);
}

TEST(RandomisedMedianTests, orderedEvenFour) {
	std::vector<double> input{0, 1, 2, 4};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	double foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	double median1 = input.at(medianIndex);
	double median2 = input.at(medianIndex + 1);
	double trueMedian = (median1 + median2) / 2;

	EXPECT_EQ(foundMedian, trueMedian);
}
TEST(RandomisedMedianTests, size1000RandomEven) {
	std::vector<double> input{};
	for (int i = 0; i < 1000; ++i) {
		input.push_back(rand());
	}
	int medianIndex = ((input.size() + 1) / 2) - 1;

	double foundMedian = findingMedian<double>(input, medianIndex);

	std::sort(input.begin(), input.end());

	double median1 = input.at(medianIndex);
	double median2 = input.at(medianIndex + 1);
	double trueMedian = (median1 + median2) / 2;

	EXPECT_EQ(foundMedian, trueMedian);
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}