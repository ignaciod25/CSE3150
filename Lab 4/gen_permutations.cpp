#include "gen_permutations.h"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>


std::vector<int> generateWellBalancedList(int n) {

    std::vector<int> sequence(2 * n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sequence[i] = 1;
        sequence[i + n + 1] = -1;
    }


    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(sequence.begin(), sequence.end(), g);


    int depth = 0;
    int minDepth = 0;
    for (int i = 0; i < 2 * n + 1; ++i) {
        depth += sequence[i];
        if (depth < minDepth) {
            minDepth = depth;
        }
    }


    std::vector<int> P1;
    for (int i = 0; i < 2 * n + 1; ++i) {
        P1.push_back(sequence[i]);
        if (P1.back() == minDepth)
            break;
    }


    std::vector<int> P2;
    for (int i = P1.size(); i < 2 * n + 1; ++i) {
        P2.push_back(sequence[i]);
    }


    P1.pop_back();


    std::vector<int> result;
    result.reserve(P2.size() + P1.size());
    result.insert(result.end(), P2.begin(), P2.end());
    result.insert(result.end(), P1.rbegin(), P1.rend());

    return result;
}
