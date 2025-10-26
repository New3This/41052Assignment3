#include "randomMedian.hpp"


int findingMedian(std::vector<int>& input, int median) {
	// selecting last element of the array as the pivot



	int pivot = input.size() - 1;
	int upperBound = input.size() - 1;
	int lowerBound = 0;
	int currentNumber = 0;
	int foundMedian = quickSelect(input, median, lowerBound, upperBound);

	return foundMedian;
}

int quickSelect(std::vector<int>& input, int median, int lowerBound, int upperBound) {

	int pivot = upperBound;
	int j = lowerBound;
	int i = lowerBound - 1;

	while (j != pivot) {
		if (input.at(j) < input.at(pivot)) {
			++i;
			std::swap(input.at(i), input.at(j));
		}
		++j;
	}
	++i;

	std::swap(input.at(i), input.at(pivot));

	for (int i : input) {
		std::cout << i << "\n";
	}
	
	if (median == input.at(i)) {
		int answer = input.at(i);
		return answer;
	}

	else if (median > input.at(i)) {
		lowerBound = i + 1;
		quickSelect(input, median, lowerBound, upperBound);
	}

	else if (median < input.at(i)) {	
		upperBound = i - 1;
		quickSelect(input, median, lowerBound, upperBound);
	}

}
