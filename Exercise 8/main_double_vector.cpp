#include <fstream>
#include <vector>

#include "double_vector.h"

using namespace std;


int main() {
    vector<double_vector> my_double_vector;

    ifstream in_file;
    in_file.open("vectors_2D.txt");

    double from, to;
    while (in_file >> from >> to) {
        double_vector d_vector = double_vector(from,to);
        my_double_vector.push_back(d_vector);
    }

    double_vector lag;
    for (auto vect : my_double_vector) {
        cout << vect.x << " " << vect.y << " " << cosine_distance(vect,vect) ;
    }
    cout << endl;

    in_file.close();

    return 0;
}