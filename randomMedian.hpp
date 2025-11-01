#ifndef RANDOMMEDIAN_HPP
#define RANDOMMEDIAN_HPP
#include <vector>
#include <algorithm>

template <typename T>
T findingMedian(std::vector<T> input, int medianIndex, bool isSecondMiddleFound = false) {
	// Return 0 if the input is empty
	if (input.size() == 0) {
		return 0;
	}

	// Return the number if the size is 1
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
	T foundMedian = quickSelect<T>(input, medianIndex, lowerBound, upperBound, isSecondMiddleFound);

	return foundMedian;
}


template <typename T>
T quickSelect(std::vector<T>& input, int medianIndex, int lowerBound, int upperBound, bool isSecondMiddleFound) {
	// Always selecting upperbound as the pivot for simplicity sake
	int pivot = upperBound;
	// Points to the first element. Represents the element in the array currently being looked at
	int currentNumber = lowerBound;
	// Points to the element before the first element
	// Represents the divider between numbers lower than the pivot and numbers greater than it
	int divider = lowerBound - 1;


	// Loop through array until pivot has been reached, i.e. all elemnts have been explored up to the upper bound
	while (currentNumber != pivot) {
		// compare if currentNumber is smaller than pivot
		if (input.at(currentNumber) < input.at(pivot)) {
			// increment divider to the next element then swap i and currentNumber
			++divider;
			std::swap(input.at(divider), input.at(currentNumber));
		}
		// go to the next element in the array
		++currentNumber;
	}
	// at the end increment divider to the next element before swapping divider with pivot
	++divider;
	std::swap(input.at(divider), input.at(pivot));


	// Median has been found
	if (medianIndex == divider) {
		T median = input.at(divider);
		// The case for when there is an even number of elements
		// isSecondMiddleFound is a flag to ensure this statement is only accessed once
		if (isEvenArraySize(input) && !isSecondMiddleFound) {
			isSecondMiddleFound = true;
			// The algorithm always finds the smaller middle number first
			// Because the formula to find the position of the median of an even set of numbers always results in a non integer
			// The datatype of medianIndex is an int so the decimal is chopped off and the number rounds down
			// So position of 2nd middle number is medianIndex + 1
			T secondMiddleNumberIndex = medianIndex + 1;
			// Running the algorithim again to find the second median number
			T secondMiddleNumber = findingMedian<T>(input, secondMiddleNumberIndex, isSecondMiddleFound);
			T sumOfMiddleNumbers = median + secondMiddleNumber;
			median = sumOfMiddleNumbers / 2;
		}
		
		return median;
	}

	// If median is greater than the pivot
	// Then that means the median can be found in the subarray containing all numbers > pivot
	// Discard subarray containing all numbers < pivot by moving the upperbound to divider + 1
	// Recurse
	else if (medianIndex > divider) {
		lowerBound = divider + 1;
		quickSelect<T>(input, medianIndex, lowerBound, upperBound, isSecondMiddleFound);
	}

	// If median is less than the pivot
	// Then that means the median can be found in the subarray containing all numbers < pivot
	// Discard subarray containing all numbers > pivot by moving the upperbound to divider - 1
	// Recurse
	else if (medianIndex < divider) {
		upperBound = divider - 1;
		quickSelect<T>(input, medianIndex, lowerBound, upperBound, isSecondMiddleFound);
	}
}

template <typename T>
bool isEvenArraySize(std::vector<T>& input) {
	return input.size() % 2 == 0;
}


#endif