#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int quickSelect(vector<int>& arr, int left, int right, int K) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);
        if (pivotIndex == K - 1) return arr[pivotIndex];
        if (pivotIndex > K - 1) return quickSelect(arr, left, pivotIndex - 1, K);
        return quickSelect(arr, pivotIndex + 1, right, K);
    }
    return -1;
}
hello 

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int K;
        cin >> K;

        if (K > n || K <= 0) {
            cout << "not present" << endl;
        } else {
            cout << quickSelect(arr, 0, n - 1, K) << endl;
        }
    }

    return 0;
}
