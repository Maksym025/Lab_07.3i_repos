#include <iostream>
#include <iomanip>
using namespace std;

void FindEqualRowsAndColumns(int** a, const int n);
int SumRowsWithNegative(int** a, const int n);

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];


    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }

  
    FindEqualRowsAndColumns(a, n);
    int sum = SumRowsWithNegative(a, n);
    cout << "Sum of elements in rows with at least one negative element: " << sum << endl;

    
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void FindEqualRowsAndColumns(int** a, const int n) {
    cout << "Rows that are equal to their corresponding columns:" << endl;
    for (int k = 0; k < n; k++) {
        bool equal = true;
        for (int j = 0; j < n; j++) {
            if (a[k][j] != a[j][k]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            cout << "Row " << k << " is equal to Column " << k << endl;
        }
    }
}

int SumRowsWithNegative(int** a, const int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        bool hasNegative = false;
        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative) {
            for (int j = 0; j < n; j++) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}
