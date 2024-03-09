#include <iostream>
#include "lambda_functions.h"

int main() {
    string line;
    int given_int;

    cout << "Enter an integer: " ;
    cin >> line;

    given_int = stoi(line);

    if (is_perfect(given_int)) {
        cout << "Perfect" << endl;
    } else {
        cout << "Imperfect" << endl;
    }
    
}