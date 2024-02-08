
#include "fisher_yates.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

void fisherYatesShuffle(int arr[], int size) {
    std::srand(std::time(0));

    for (int i = size - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}