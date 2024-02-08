#include <iostream>
#include <cstdlib>

#include "fisher_yates.h"


using namespace std;

int main() {
    string n_string;
    cout << "Enter the number of open-parens: " << endl;
    cin >> n_string;

    int n;

    n = stoi(n_string);

    cout << n << endl;

    int arrayValues[2*n];

    for (int i =0; i < n; i++) {
        arrayValues[i] = 1;
    }

    for (int i =0; i < n; i++) {
        arrayValues[i+n] = -1;
    }

   /*cout << arrayValues <<endl;*/

    print_array(arrayValues, 2*n);

    return 0;
}

