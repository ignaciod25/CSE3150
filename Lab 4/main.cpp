#include "gen_permutations.h"
#include <iostream>

int main() {

    int n = 3;  
    auto result = generateWellBalancedList(n);


    std::cout << "Generated Well-Balanced List: ";
    for (const auto& symbol : result) {
        std::cout << symbol << ' ';
    }
    std::cout << std::endl;

    return 0;
}
