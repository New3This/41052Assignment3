#include "randomMedian.hpp"


int findingMedian(std::vector<int>& input, int median) {
	// selecting last element of the array as the pivot
	int pivot = input.size() - 1;
	int greater = input.size() - 1;
	int lesser = 0;
	int currentNumber = 0;
	quickSelect(input, median, lesser, greater);

	return 0;
}

int quickSelect(std::vector<int>& input, int median, int lesser, int greater) {
	int pivot = greater;
	int j = lesser;
	int i = lesser - 1;

	while(j != pivot) {
		//std::cout << input.at(j);
		if (input.at(j) < input.at(pivot)) {
			++i;
			std::cout << " i " << input.at(i) << " j " << input.at(j) << "\n";
			std::swap(input.at(i), input.at(j));
		}
		++j;
	}
	++i;
	std::swap(input.at(i), input.at(pivot));

	if (pivot == median) {
		return input.at(median);
	}

	std::cout << "\n";
	for (int i : input) {
		std::cout << i << "\n";
	}



	return 0;

}
