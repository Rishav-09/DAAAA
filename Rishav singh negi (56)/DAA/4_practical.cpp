#include <iostream>
#include <vector>
using namespace std;

int binary_search_first(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int binary_search_last(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}
int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> target;
    int first = binary_search_first(arr, target);
    if (first == -1) {
        cout << "Element not found" << endl;
    } else {
        int last = binary_search_last(arr, target);
        cout << "Frequency of " << target << " is " << last - first + 1 << endl;
    }
    return 0;
}
