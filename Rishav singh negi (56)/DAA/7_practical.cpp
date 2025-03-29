#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cout << "Enter Number of Test Cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter Size Of Array: ";
        cin >> n;
        vector<int> v1(n);
        cout << "Enter Elements Of Array: ";
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }

        int comparisons = 0, shifts = 0;
        for (int i = 1; i < n; i++) {
            int prev = i - 1;
            int curr = v1[i];
            while (0 <= prev && v1[prev] > curr) {
                v1[prev + 1] = v1[prev];
                prev--;
                comparisons++;
                shifts++;
            }
            v1[prev + 1] = curr;
            if (prev != i - 1) shifts++;
        }

        cout << "Array after Sorting: ";
        for (int i = 0; i < n; i++) {
            cout << v1[i] << " ";
        }
        cout << "\nComparisons = " << comparisons;
        cout << "\nShifts = " << shifts << endl;
    }

    return 0;
}









