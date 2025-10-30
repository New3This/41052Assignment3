#ifndef RANDOMMEDIAN_HPP
#define RANDOMMEDIAN_HPP
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
T findingMedian(std::vector<T>& input, int medianIndex, bool isSecondMiddleFound = false) {
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
	int i = lowerBound - 1;


	// Loop through array until pivot has been reached, i.e. all elemnts have been explored up to the upper bound
	while (currentNumber != pivot) {
		// compare if currentNumber is smaller than pivot
		if (input.at(currentNumber) < input.at(pivot)) {
			// increment i to the next element then swap i and currentNumber
			++i;
			std::swap(input.at(i), input.at(currentNumber));
		}
		// go to the next element in the array
		++currentNumber;
	}
	// at the end increment i to the next element before swapping i with pivot
	++i;
	std::swap(input.at(i), input.at(pivot));


	// Median has been found
	if (medianIndex == i) {
		T median = input.at(i);
		if (isEvenArraySize(input) && !isSecondMiddleFound) {
			isSecondMiddleFound = true;
			T secondMiddleNumberIndex = medianIndex + 1;
			T secondMiddleNumber = findingMedian<T>(input, secondMiddleNumberIndex, isSecondMiddleFound);
			std::cout << secondMiddleNumber << " second\n";
			T sumOfMiddleNumbers = median + secondMiddleNumber;
			median = sumOfMiddleNumbers / 2;
			int x = 0;
		}
		
		return median;
	}

	// If median is greater than the pivot
	// Then that means the median can be found in the subarray containing all numbers > pivot
	// Discard subarray containing all numbers < pivot by moving the upperbound to i + 1
	// Recurse
	else if (medianIndex > i) {
		lowerBound = i + 1;
		quickSelect<T>(input, medianIndex, lowerBound, upperBound, isSecondMiddleFound);
	}

	// If median is less than the pivot
	// Then that means the median can be found in the subarray containing all numbers < pivot
	// Discard subarray containing all numbers > pivot by moving the upperbound to i - 1
	// Recurse
	else if (medianIndex < i) {
		upperBound = i - 1;
		quickSelect<T>(input, medianIndex, lowerBound, upperBound, isSecondMiddleFound);
	}
}

template <typename T>
bool isEvenArraySize(std::vector<T>& input) {
	return input.size() % 2 == 0;
}


#endif