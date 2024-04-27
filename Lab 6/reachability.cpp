#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


vector<vector<double>> matrixMultiplication(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int n = A.size();
    vector<vector<double>> result(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

vector<vector<double>> initializeMatrix(int n, double initialValue) {
    return vector<vector<double>>(n, vector<double>(n, initialValue));
}


void normalizeMatrix(vector<vector<double>>& matrix) {
    int n = matrix.size();
    double sum = 0.0;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
        }
    }


    if (sum != 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] /= sum;
            }
        }
    }
}

int main() {

    ifstream infile("sample_matrix.txt");
    if (!infile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return 1;
    }

    int n;
    infile >> n; 

    vector<vector<double>> D0(n, vector<double>(n, 0.0)); 


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> D0[i][j];
        }
    }

    infile.close();


    vector<vector<double>> A = initializeMatrix(n, 0.0);


    A = matrixMultiplication(D0, D0); 


    normalizeMatrix(A);


    cout << "rows: " << A.size() << " size: " << A[0].size() << endl;
    cout << "--------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------" << endl;

    return 0;
}
