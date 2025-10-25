#ifndef RANDOMMEDIAN_HPP
#define RANDOMMEDIAN_HPP
#include <vector>
#include <algorithm>
#include <iostream>

int findingMedian(std::vector<int>& input, int median);

int quickSelect(std::vector<int>& input, int median, int lesser, int greater);

#endif
