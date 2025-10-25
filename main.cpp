#include "randomMedian.hpp"
#include "gtest/gtest.h"
int main() {
	std::vector<int> input {4, 0, 3, 2, 1};
	int median = ((input.size() + 1) / 2) - 1;
	findingMedian(input, median);
	return 0;
}