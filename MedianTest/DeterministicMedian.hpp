#pragma once
#include <vector>
#include <algorithm>
#include <optional>


template <typename T>
T recurseLocate(std::vector<T>& array, T median, int pivotRank);

template <typename T>
T partitionArray(std::vector<T>& array, int pivotRank) {
    std::vector<T> mediansList;
    T medianofMedians = 0;

    // split the array into groups of 5
    for (int i = 0; i < array.size();) {
        std::vector<T>subArray;
        // (for last grouping) adjust subArray size if less than 5 elements left to be grouped
        if (i == array.size() - (array.size() % 5) && array.size() % 5 != 0) {
            subArray = std::vector<T>(array.begin() + i, array.begin() + i + array.size() % 5);
            i += array.size() % 5;
        }
        // otherwise store every 5
        else {
            subArray = std::vector<T>(array.begin() + i, array.begin() + i + 5);
            i += 5;
        }

        std::sort(subArray.begin(), subArray.end()); // since each subarray is at most size of 5, its sort cost is O(1) preserving the deterministics guarantee of O(n) altogether
        mediansList.push_back(subArray[subArray.size() / 2]); // store the median of each subarray into an array - forms median of median array
    }

    if (mediansList.size() <= 5) { // if medianList is less than 5
        std::sort(mediansList.begin(), mediansList.end()); // we can sort
        medianofMedians = mediansList[mediansList.size() / 2];
    }
    else { // otherwise find median recursively if too expensive for sort
        medianofMedians = partitionArray(mediansList, mediansList.size() / 2);
    }
    // then we recurse further until pivotRank is found
    return recurseLocate(array, medianofMedians, pivotRank);

}

template <typename T>
T recurseLocate(std::vector<T>& array, T median, int pivotRank) {
    std::vector<T> leftArray;
    std::vector<T> rightArray;
    std::vector<T> middleArray;
    // split the medians of medians array into three arrays
    for (T element : array) {
        if (element < median) {
            leftArray.push_back(element);
        }
        else if (element == median) {
            middleArray.push_back(element);
        }
        else {
            rightArray.push_back(element);
        }
    }


    if (pivotRank < leftArray.size()) { // recuse into leftArray if the median exists in there
        if (leftArray.size() <= 5) { // when less than or equal to 5
            std::sort(leftArray.begin(), leftArray.end()); // sorting is affordable
            return leftArray[pivotRank]; // we can finally return median
        }
        return partitionArray(leftArray, pivotRank); // otherwise, recurse

    }
    else if (pivotRank < leftArray.size() + middleArray.size()) { // if its in middleArray
        return middleArray[0]; // we return any of the values, i.e. first one -- since all values in middleArray are equal (hence no recursion needed to find median)
    }
    else { // otherwise if on right side
        int updatedPivotRank = pivotRank - (leftArray.size() + middleArray.size()); // update pivotRank to adapt to new array size
        // rest same as line 65 (the if condition)
        if (rightArray.size() <= 5) {
            std::sort(rightArray.begin(), rightArray.end());
            return rightArray[updatedPivotRank];
        }
        return partitionArray(rightArray, updatedPivotRank);
    }
}

template <typename T>
std::optional<T> DeterministicMedian(std::vector<T>& array) {

    if (array.empty()) { // if nothing in array
        return std::nullopt; // indicate it does not contain a value
    }
    
    int pivotRank = array.size() / 2;

    else if (array.size() % 2 == 1) { // if array is odd
        return partitionArray(array, pivotRank); // perform recursive partioning to find middle value/median
    }
    else if (array.size() % 2 == 0) { // otherwise its even
        T firstMedian = partitionArray(array, (pivotRank) - 1); // find first middle value
        T secondMedian = partitionArray(array, (pivotRank)); // second middle value
        return (firstMedian + secondMedian) / 2.0; // average of both middle values gives overall median
    }
}