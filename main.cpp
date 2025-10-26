#include "randomMedian.hpp"
#include "gtest/gtest.h"

TEST(odd5, ex6) {
	std::vector<int> input{ 4, 0, 3, 2, 1 };
	int median = ((input.size() + 1) / 2) - 1;
	int foundMedian = findingMedian(input, median);
	EXPECT_EQ(foundMedian, median);
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}