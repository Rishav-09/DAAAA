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

        sort(v1.begin(), v1.end());

        bool hasDuplicate = false;
        for (int i = 1; i < n; i++) {
            if (v1[i] == v1[i - 1]) {
                hasDuplicate = true;
                break;
            }
        }

        if (hasDuplicate) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
