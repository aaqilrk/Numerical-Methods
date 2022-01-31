// Lagrange's Interpolation Method
#include <iostream>
using namespace std;

float lagrange(float X[], float Y[], int n, float x) {
    float term, sum = 0;

    // Algorithim to find y value
    for (int i = 0; i < n; i++) {
        term = 1;
        for (int j = 0; j < n; j++) {
            if (i != j)
                term = term * ((x - X[j]) / (X[i] - X[j]));
        }
        sum = sum + term * Y[i];
    }
    return sum;
}

int main() {
    int n;
    float X[100], Y[100], x;

    // Taking count of no of data points
    cout << "Enter no. of terms: ";
    cin >> n;

    // Taking values of x
    cout << "Enter Values of x: ";
    for (int i = 0; i < n; i++)
        cin >> X[i];

    // Taking values of y
    cout << "Enter Values of y: ";
    for (int i = 0; i < n; i++)
        cin >> Y[i];

    // Taking value of x for which we want value of y
    cout << "Enter value of x for which you want y: ";
    cin >> x;

    cout << "y = " << lagrange(X, Y, n, x);

    return 0;
}