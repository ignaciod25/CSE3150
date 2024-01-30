// prefix_sum.cpp

#include "prefix_sum.h"

int prefix_sum(int* nums, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
    }
    return sum;
}

bool non_negative_sum(int* nums, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
        if (sum < 0) {
            return false;
        }
    }
    return true;
}

bool non_positive_sum(int* nums, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
        if (sum > 0) {
            return false;
        }
    }
    return true;
}
