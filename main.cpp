#include "randomMedian.hpp"
#include "gtest/gtest.h"

TEST(emptySet, ex1) {
	std::vector<int> input{};
	int medianIndex = 0;
	int foundMedian = findingMedian(input, medianIndex);
	EXPECT_EQ(foundMedian, medianIndex);
}
/*
TEST(sizeOne, ex2) {
	std::vector<int> input{1};

	int foundMedian = findingMedian(input, 0);

	EXPECT_EQ(foundMedian, 1);
}

TEST(orderedEvenFour, ex3) {
	std::vector<int> input{0, 1, 2, 4};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median1 = input.at(medianIndex);
	int median2 = input.at(medianIndex + 1);
	int trueMedian = (median1 + median2) / 2;

	std::cout << trueMedian << "\n";

	EXPECT_EQ(foundMedian, trueMedian);
}

TEST(unorderedOddThree, ex4) {
	std::vector<int> input{9, 2, 15};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	std::cout << median << "\n";

	EXPECT_EQ(foundMedian, median);
}

TEST(identicalNumbers, ex5) {
	std::vector<int> input{1, 1, 1, 1, 1, 1};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	std::cout << median << "\n";

	EXPECT_EQ(foundMedian, median);
}


TEST(unorderedOddFive, ex6) {
	std::vector<int> input{4, 0, 3, 2, 1};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	std::cout << median << "\n";

	EXPECT_EQ(foundMedian, median);
}


TEST(negativeNumbers, ex7) {
	std::vector<int> input{-8, -10, -5, -20, -16};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	std::cout << median << "\n";

	EXPECT_EQ(foundMedian, median);
}


TEST(negativeAndPositiveNumbers, ex8) {
	std::vector<int> input{20, -1, -9, 11, 2, 3, -99};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	std::cout << median << "\n";

	EXPECT_EQ(foundMedian, median);
}

TEST(medianIndexAtEnd, ex9) {
	std::vector<int> input{1, 2, 3, 5, 6, 7, 4};

	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	std::cout << median << "\n";

	EXPECT_EQ(foundMedian, median);
}

TEST(size10000, ex) {
	std::vector<int> input{};
	for (int i = 0; i < 1000; ++i) {
		input.push_back(i);
	}
	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	std::cout << median << "\n";

	EXPECT_EQ(foundMedian, median);
}

TEST(size1000Random, exx) {
	std::vector<int> input{};
	for (int i = 0; i < 1000; ++i) {
		input.push_back(rand());
	}
	int medianIndex = ((input.size() + 1) / 2) - 1;

	int foundMedian = findingMedian(input, medianIndex);

	std::sort(input.begin(), input.end());

	int median = input.at(medianIndex);

	std::cout << median << "\n";

	EXPECT_EQ(foundMedian, median);
}
*/
int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}