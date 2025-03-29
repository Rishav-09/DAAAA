#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>& v1, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    vector<int> temp(high - low + 1);
    int inversions=0;
    while (i <= mid && j <= high) {
        if (v1[i] <= v1[j]) {
            temp[k++] = v1[i++];
        } else {
            temp[k++] = v1[j++];
            inversions += (mid - i + 1);
        }
    }
    while (i <= mid) temp[k++] = v1[i++];
    while (j <= high) temp[k++] = v1[j++];

    for (int x = 0; x < k; x++) {
        v1[low+x]=temp[x];
    }
    return inversions;
}

int mergeSort(vector<int>& v1, int low, int high) {
    int inversions=0; 
    if (low < high) {
        int mid = low + (high - low) / 2;
        inversions+=mergeSort(v1, low, mid);
        inversions+=mergeSort(v1, mid + 1, high);
        inversions+=merge(v1, low, mid, high);
    }
    return inversions;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v1(n);
        for (int i = 0; i < n; i++) cin >> v1[i];
        int inversions=0;
        inversions = mergeSort(v1, 0, n - 1);
        for (int i = 0; i < n; i++) cout << v1[i] << " ";
        cout << endl;
        cout << "Inversions: " << inversions << endl;
    }

    return 0;
}
