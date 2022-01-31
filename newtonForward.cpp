// Newton Forward Interpolation Method
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
float newtonsForwardInterpolation(float a[100][100], int n, float x) {
    // find p
    float p = (x - a[0][0]) / (a[1][0] - a[0][0]);

    // Initial y, p1, k
    float y = a[0][1];
    float p1 = p;
    int fact = 1;

    // Algorithim to find y value
    for (int i = 2; i <= n; i++) {
        y = y + (p1 * a[0][i]) / fact;
        // Update fact, p1
        fact = fact * i;
        p1 = p1 * (p - (i - 1));
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
    cout << "Enter value of x for which you want value of y: ";
    cin >> x;

    createDifferenceTable(a, n);

    printDifferenceTable(a, n);

    cout << "y = " << newtonsForwardInterpolation(a, n, x);

    return 0;
}