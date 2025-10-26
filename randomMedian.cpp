#include "randomMedian.hpp"


int findingMedian(std::vector<int>& input, int median) {
	if (input.size() == 0) {
		return 0;
	}

	if (input.size() == 1) {
		return input.at(0);
	}
	// The pivot is the selected number that will be compared against every other number to find its correct spot
	int pivot = input.size() - 1;
	// The highest point of the array (index wise) the algorithm will consider
	// Used to discard uneeded subarrays
	// Intiialise last element as the lower bound
	int upperBound = input.size() - 1;
	// The lowest point of the array (index wise) the algorithm will consider
	// Initialise first element as the lower bound
	int lowerBound = 0;
	int foundMedian = quickSelect(input, median, lowerBound, upperBound);

	return foundMedian;
}

int quickSelect(std::vector<int>& input, int median, int lowerBound, int upperBound) {
	// Always selecting upperbound as the pivot for simplicity sake
	int pivot = upperBound;
	// Points to the first element
	int j = lowerBound;
	// Points to the element before the first element
	// Represents the divider between numbers lower than the pivot and numbers greater than it
	int i = lowerBound - 1;

	// Loop through array until pivot has been reached, i.e. all elemnts have been explored up to the upper bound
	while (j != pivot) {
		// Compare 
		if (input.at(j) < input.at(pivot)) {
			++i;
			std::swap(input.at(i), input.at(j));
		}
		++j;
	}
	++i;

	std::swap(input.at(i), input.at(pivot));

	//for (int i : input) {
		//std::cout << i << "\n";
	//}
	
	// Median has been found
	if (median == input.at(i)) {
		int answer = input.at(i);
		return answer;
	}

	// If median is greater than the pivot
	// Then that means the median can be found in the subarray containing all numbers > pivot
	// Discard subarray containing all numbers < pivot by moving the upperbound to i + 1
	// Recurse
	else if (median > input.at(i)) {
		lowerBound = i + 1;
		quickSelect(input, median, lowerBound, upperBound);
	}

	// If median is less than the pivot
	// Then that means the median can be found in the subarray containing all numbers < pivot
	// Discard subarray containing all numbers > pivot by moving the upperbound to i - 1
	// Recurse
	else if (median < input.at(i)) {	
		upperBound = i - 1;
		quickSelect(input, median, lowerBound, upperBound);
	}

}
