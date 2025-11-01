#pragma once
#include <vector>
#include <algorithm>
#include <optional>


template <typename T>
T pivotLocate(std::vector<T>& array, int leftSide, int rightSide, T median, int pivotRank);

template <typename T>
T partitionArray(std::vector<T>& array, int leftSide, int rightSide, int pivotRank) {
    std::vector<T> mediansList;
    T medianofMedians = 0;
    int partitionSize = 0;

    // split the array into groups of 5
    for (int i = leftSide; i <= rightSide;) {
        
        // (for last grouping) adjust subArray size if less than 5 elements left to be grouped
        if (rightSide - i + 1 < 5) {
            partitionSize = rightSide - i + 1;
        }
        // otherwise store every 5
        else {
            partitionSize = 5;
        }

        std::sort(array.begin() + i, array.begin() + i + partitionSize); // since each subarray is at most size of 5, its sort cost is O(1) preserving the deterministics guarantee of O(n) altogether
        mediansList.push_back(array[i + partitionSize / 2]); // store the median of each subarray into an array - forms median of median array
        i += partitionSize;
    }

    if (mediansList.size() <= 5) { // if medianList is less than 5
        std::sort(mediansList.begin(), mediansList.end()); // we can sort
        medianofMedians = mediansList[mediansList.size() / 2];
    }
    else { // otherwise find median recursively if too expensive for sort
        medianofMedians = partitionArray(mediansList, 0, mediansList.size() - 1, mediansList.size() / 2);
    }
    // then we recurse further until pivotRank is found
    return pivotLocate(array, leftSide, rightSide, medianofMedians, pivotRank);
}

template <typename T>
T pivotLocate(std::vector<T>& array, int leftSide, int rightSide, T median, int pivotRank) {
    int i = leftSide;
    int leftRecurse = leftSide;
    int rightRecurse = rightSide;

    while (i <= rightRecurse) {// "sorts" the values,
        if (array[i] < median) { // where values less than median
            std::swap(array[i], array[leftRecurse]); // go to left side of median
            i++;
            leftRecurse++;
        }
        else if (array[i] > median) { // else if value bigger than median
            std::swap(array[i], array[rightRecurse]); // go to right side of median
            rightRecurse--;
        }
        else { // else if equals to median
            i++; // no swap just check next value
        }
    }

    if (pivotRank < leftRecurse - leftSide) { // if median rank is in left of median
        return partitionArray(array, leftSide, leftRecurse - 1, pivotRank); // recurse into left values
    }
    else if (pivotRank < leftSide + rightRecurse + 1) { // if median rank is at median
        return median; // return median
    }
    else {
        return partitionArray(array, rightRecurse + 1, rightSide, pivotRank + leftSide - rightRecurse - 1);
    }
}

template <typename T>
std::optional<T> DeterministicMedian(std::vector<T>& array) {
    int pivotRank = array.size() / 2;

    if (array.empty()) { // if nothing in array
        return std::nullopt; // indicate it does not contain a value
    }


    else if (array.size() % 2 == 1) { // if array is odd
        return partitionArray(array, 0, array.size() - 1, pivotRank); // perform recursive partioning to find middle value/median
    }
    else if (array.size() % 2 == 0) { // otherwise its even
        T firstMedian = partitionArray(array, 0, array.size() - 1, pivotRank - 1); // find first middle value
        T secondMedian = partitionArray(array, 0, array.size() - 1, pivotRank); // second middle value
        return (firstMedian + secondMedian) / 2.0; // average of both middle values gives overall median
    }
}