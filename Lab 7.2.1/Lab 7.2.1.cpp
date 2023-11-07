#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int k, const int n) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

int FindLargestOfMinimums(int** a, const int k, const int n) {
    if (k <= 0 || n <= 0) {
        return -1;
    }

    int largestMin = 0;

    for (int i = 0; i < k; i++) {
        int minInRow = a[i][0];

        for (int j = 1; j < n; j++) {
            if (a[i][j] < minInRow) {
                minInRow = a[i][j];
            }
        }

        if (minInRow > largestMin) {
            largestMin = minInRow;
        }
    }

    return largestMin;
}

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int result = FindLargestOfMinimums(a, k, n);

    if (result != -1)
        cout << "The largest of the minimum elements in each row: " << result << endl;
    else
        cout << "Matrix is empty." << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
