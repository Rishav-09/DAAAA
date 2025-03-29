#include <bits/stdc++.h>
using namespace std;

int maxval(vector<int> &v1, int n) {
    int max_val = v1[0];
    for (int i = 1; i < n; i++) {
        if (v1[i] > max_val) {
            max_val = v1[i];
        }
    }
    return max_val;
}

void input(vector<int> &v1, int n) {
    cout << "Enter Element of vector: ";
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
}

void print(const vector<int> &v1, int n) {
    cout << "Elements of Array are: ";
    for (int i = 0; i < n; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
}

vector<int> count_sort(vector<int> &v1, int n, int max_val) {
    vector<int> count(max_val + 1, 0);
    vector<int> output(n);

    for (int i = 0; i < n; i++) {
        count[v1[i]]++;
    }

    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[v1[i]] - 1] = v1[i];
        count[v1[i]]--;
    }
    return output;
}

int main() {
    cout << "Size of array: ";
    int n;
    cin >> n;
    vector<int> v1(n);
    input(v1, n);
    int max_val = maxval(v1, n);
    v1 = count_sort(v1, n, max_val);
    print(v1, v1.size());
}
