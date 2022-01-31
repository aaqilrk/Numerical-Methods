// Newton backward Interpolation Method
#include <iostream>
using namespace std;

// Creates Difference Table
void createDifferenceTable(float a[100][100], int n) {
    for (int j = 2; j < n + 1; j++) {
        for (int i = 0; i < n - j + 1; i++)
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
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

// returns corresponding y value for given x value
float newtonsBackwardInterpolation(float a[100][100], int n, float x) {
    // find p
    float p = (x - a[n - 1][0]) / (a[1][0] - a[0][0]);

    // Initial y, k, p1, j
    float y = a[n - 1][1];
    float p1 = p;
    int fact = 1;

    // corresponds to column no.
    int j = 2;

    // Algorithim to find y value
    for (int i = n - 2; i >= 0; i--) {
        y = y + (p1 * a[i][j]) / fact;
        // Update k, p1, j
        fact = fact * j;
        p1 = p1 * (p + (j - 1));
        j++;
    }

    return y;
}

int main() {
    float x, a[100][100];
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

    cout << "y = " << newtonsBackwardInterpolation(a, n, x);

    return 0;
}