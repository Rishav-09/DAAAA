#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cout << "Enter Number of Test Cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter Size of Array: ";
        cin >> n;
        vector<int> v1(n);
        cout << "Enter Elements of Array: ";
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }

        int comparisons = 0, swaps = 0;
        for (int i = 0; i < n - 1; i++) {   
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (v1[j] < v1[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(v1[minIndex], v1[i]);
                swaps++;
            }
        }

        cout << "Array after Sorting: ";
        for (int i = 0; i < n; i++) {
            cout << v1[i] << " ";
        }
        cout << "\nComparisons = " << comparisons;
        cout << "\nSwaps = " << swaps << endl;
    }

    return 0;
}
