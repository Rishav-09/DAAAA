#include <bits/stdc++.h>
using namespace std;
int comparisons = 0;
int swaps = 0;
int partition(vector<int>& v1, int start, int end) {
    int pivot = v1[end];  
    int idx = start - 1;  
    for (int i = start; i < end; i++) {
        comparisons++;
        if (v1[i] <= pivot) {
            idx++;
            swap(v1[i], v1[idx]);
            swaps++;
        }
    }
    idx++;
    swap(v1[idx], v1[end]);
    swaps++;
    return idx;
}

void quicksort(vector<int>& v1, int start, int end) {
    if (start < end) {
        int pivot = partition(v1, start, end);
        quicksort(v1, start, pivot - 1);
        quicksort(v1, pivot + 1, end);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v1(n);
        for (int i = 0; i < n; i++) cin >> v1[i];
        comparisons = 0;
        swaps = 0;
        quicksort(v1, 0, n - 1);
        for (int i = 0; i < n; i++) cout << v1[i] << " ";
        cout << endl;
        cout << "Comparisons: " << comparisons << endl;
        cout << "Swaps: " << swaps << endl;
    }

    return 0;
}
