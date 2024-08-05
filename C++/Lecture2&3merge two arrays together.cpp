#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

int main() {
    int arr1[5] = {0, 1, 2, 3, 4};
    int size1 = 5;


   
    int arr2[5] = {5, 6, 7, 8, 9};
    int size2 = 5;

    
    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];

    for (int i = 0; i < size1; ++i) {
        mergedArray[i] = arr1[i];
    }

    for (int i = 0; i < size2; ++i) {
        mergedArray[size1 + i] = arr2[i];
    }
    
    for (int i = 0; i < mergedSize; ++i) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


