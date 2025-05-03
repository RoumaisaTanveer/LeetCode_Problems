#include <iostream>
#include <vector>

using namespace std;

// Function to compare triplets
vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int aliceScore = 0, bobScore = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            aliceScore++;
        } else if (a[i] < b[i]) {
            bobScore++;
        }
    }

    return {aliceScore, bobScore};
}

int main() {
    vector<int> a(3), b(3);

    // Debugging statement
    // cout << "Enter Alice's ratings (3 space-separated integers): ";
    for (int i = 0; i < 3; i++) {
        cin >> a[i]; 
    }

    // Debugging statement
    // cout << "Enter Bob's ratings (3 space-separated integers): ";
    for (int i = 0; i < 3; i++) {
        cin >> b[i]; 
    }

    // Print the values to ensure they were taken correctly
    // cout << "Alice: ";
    // for (int i = 0; i < 3; i++) cout << a[i] << " ";
    // cout << endl;

    // cout << "Bob: ";
    // for (int i = 0; i < 3; i++) cout << b[i] << " ";
    // cout << endl;

    // Compute scores
    vector<int> result = compareTriplets(a, b);

    // Print result
    cout  << result[0] << " " << result[1] << endl;

    return 0;
}
