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
    for (int i = 0; i < array.size();) {
        std::vector<T>subArray;
        if (i == array.size() - (array.size() % 5) && array.size() % 5 != 0) {
            subArray = std::vector<T>(array.begin() + i, array.begin() + i + array.size() % 5);
            i += array.size() % 5;
        }
        else {
            subArray = std::vector<T>(array.begin() + i, array.begin() + i + 5);
            i += 5;
        }

        std::sort(subArray.begin(), subArray.end());
        mediansList.push_back(subArray[subArray.size() / 2]);
    }

    if (mediansList.size() <= 5) {
        std::sort(mediansList.begin(), mediansList.end());
        medianofMedians = mediansList[mediansList.size() / 2];
    }
    else { // find median recursively if too expensive for sort
        medianofMedians = partitionArray(mediansList, mediansList.size() / 2);
    }
    // otherwise, too expensive to sort and so we recurse as is
    return recurseLocate(array, medianofMedians, pivotRank);

}

template <typename T>
T recurseLocate(std::vector<T>& array, T median, int pivotRank) {
    std::vector<T> leftArray;
    std::vector<T> rightArray;
    std::vector<T> middleArray;

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


    if (pivotRank < leftArray.size()) {
        if (leftArray.size() <= 5) { // less than or equal to 5 allows sorting since O(1) operation
            std::sort(leftArray.begin(), leftArray.end());
            return leftArray[pivotRank];
        }
        return partitionArray(leftArray, pivotRank);

    }
    else if (pivotRank < leftArray.size() + middleArray.size()) {
        return middleArray[0]; // since all values the say same
    }
    else {
        int updatedPivotRank = pivotRank - (leftArray.size() + middleArray.size());
        if (rightArray.size() <= 5) {
            std::sort(rightArray.begin(), rightArray.end());
            return rightArray[updatedPivotRank];
        }
        return partitionArray(rightArray, updatedPivotRank);
    }
}

template <typename T>
std::optional<T> DeterministicMedian(std::vector<T>& array) {
    int pivotRank = array.size() / 2;
    if (array.empty()) {
        return std::nullopt;
    }
    else if (array.size() % 2 == 1) {
        return partitionArray(array, pivotRank);
    }
    else if (array.size() % 2 == 0) {
        double firstMedian = partitionArray(array, (array.size() / 2) - 1);
        double secondMedian = partitionArray(array, (array.size() / 2));
        return (firstMedian + secondMedian) / 2.0;
    }
}