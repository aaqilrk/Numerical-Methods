// Newton Divided Difference Method
#include <iostream>
using namespace std;

// Creates Difference Table
void createDifferenceTable(float a[100][100], int n) {
    for (int j = 2; j < n + 1; j++) {
        for (int i = 0; i < n - j + 1; i++)
            a[i][j] = (a[i + 1][j - 1] - a[i][j - 1]) / (a[i + j - 1][0] - a[i][0]);
    }
}

// Prints Difference Table
void printDifferenceTable(float a[100][100], int n) {
    cout << "The Difference Table is as follows: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

// Returns corresponding y value for given x value
float dividedDifference(float a[100][100], int n, int x) {
    float y = a[0][1];

    for (int i = 0; i <= n - 2; i++) {
        float temp = 1;
        for (int j = 0; j <= i; j++)
            temp *= x - a[j][0];
        y += temp * a[0][i + 2];
    }

    return y;
}

int main() {
    float x, y, a[100][100];
    int n;

    // Taking count of no of data points
    cout << "Enter no of terms: ";
    cin >> n;

    // Taking values of x
    cout << "Enter values of x: ";
    for (int i = 0; i < n; i++)
        cin >> a[i][0];

    // Taking values of y
    cout << "Enter values of y: ";
    for (int i = 0; i < n; i++)
        cin >> a[i][1];

    // Taking value of x for which we want value of y
    cout << "Enter value of x for which you want y: ";
    cin >> x;

    createDifferenceTable(a, n);

    printDifferenceTable(a, n);

    cout << "y = " << dividedDifference(a, n, x);

    return 0;
}