#include "randomMedian.hpp"
#include "gtest/gtest.h"

TEST(emptySet, ex1) {
	std::vector<int> input{};
	int median = 0;
	int foundMedian = findingMedian(input, median);
	EXPECT_EQ(foundMedian, median);
}

TEST(sizeOne, ex2) {
	std::vector<int> input{1};
	int median = input.at(((input.size() + 1) / 2) - 1);
	int foundMedian = findingMedian(input, median);
	EXPECT_EQ(foundMedian, median);
}

TEST(evenTwo, ex3) {
	std::vector<int> input{0, 1, 2, 4};
	int median = input.at(((input.size() + 1) / 2) - 1);
	int foundMedian = findingMedian(input, median);
	std::cout << median << " median\n";
	EXPECT_EQ(foundMedian, median);
}


TEST(oddFive, ex6) {
	std::vector<int> input{ 4, 0, 3, 2, 1 };
	int median = input.at(((input.size() + 1) / 2) - 1);
	int foundMedian = findingMedian(input, median);
	EXPECT_EQ(foundMedian, median);
}



int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}