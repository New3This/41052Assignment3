#include "randomMedian.hpp"


int findingMedian(std::vector<int>& input, int median) {
	// selecting last element of the array as the pivot
	int pivot = input.size() - 1;
	int upperBound = input.size() - 1;
	int lowerBound = 0;
	int currentNumber = 0;
	quickSelect(input, median, lowerBound, upperBound);

	return 0;
}

int quickSelect(std::vector<int>& input, int median, int lowerBound, int upperBound) {

	int pivot = upperBound;
	std::cout << "\n" << "pivot " << pivot << "\n";
	int j = lowerBound;
	int i = lowerBound - 1;

	while (j != pivot) {
		//std::cout << input.at(j);
		if (input.at(j) < input.at(pivot)) {
			++i;
	//		std::cout << " i " << input.at(i) << " j " << input.at(j) << "\n";
			std::swap(input.at(i), input.at(j));
		}
		++j;
	}
	++i;
	std::swap(input.at(i), input.at(pivot));

	for (int i : input) {
		std::cout << i << "\n";
	}

	if (input.at(i) == median) {
		std::cout << " \nhi ";
		return input.at(median);
	}
	else if (median > input.at(i)) {
		std::cout << "\nlowerBound " << lowerBound << "\n";
		lowerBound = i + 1;
		std::cout << "\n new lowerBound " << lowerBound << "\n";
		quickSelect(input, median, lowerBound, upperBound);
	}
	else if (median < input.at(i)) {
		std::cout << "upperBound " << upperBound << "\n";
		upperBound = i - 1;
		std::cout << "\n new upperBound " << upperBound << "\n";
		quickSelect(input, median, lowerBound, upperBound);
	}

	std::cout << "\n";
	





	return 0;

}
