#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Define all 8 possible 3x3 magic squares
    int magicSquares[8][9] = {
        {4, 9, 2, 3, 5, 7, 8, 1, 6},
        {2, 7, 6, 9, 5, 1, 4, 3, 8},
        {6, 1, 8, 7, 5, 3, 2, 9, 4},
        {2, 9, 4, 7, 5, 3, 6, 1, 8},
        {6, 7, 2, 1, 5, 9, 8, 3, 4},
        {8, 1, 6, 3, 5, 7, 4, 9, 2},
        {8, 3, 4, 1, 5, 9, 6, 7, 2},
        {4, 3, 8, 9, 5, 1, 2, 7, 6}
    };

    int input[9]; // Store user input matrix
    int minCost = INT_MAX; // Store minimum cost
    int bestMagicSquare[9]; // Store the best magic square

    // Read the 3x3 input matrix as a 1D array
    for (int i = 0; i < 9; i++) {
        cin >> input[i];
    }

    // Check the cost for each magic square
    for (int i = 0; i < 8; i++) {
        int cost = 0;
        for (int j = 0; j < 9; j++) {
            cost += abs(input[j] - magicSquares[i][j]);
        }

        // Update minimum cost and store the best magic square
        if (cost < minCost) {
            minCost = cost;
            for (int k = 0; k < 9; k++) {
                bestMagicSquare[k] = magicSquares[i][k];
            }
        }
    }

    // Print the minimum cost
    cout << "Minimum Cost: " << minCost << endl;

    // Print the resulting magic square
    cout << "Transformed Magic Square:" << endl;
    for (int i = 0; i < 9; i++) {
        cout << bestMagicSquare[i] << " ";
        if ((i + 1) % 3 == 0) cout << endl; // Print in 3x3 format
    }

    return 0;
}
