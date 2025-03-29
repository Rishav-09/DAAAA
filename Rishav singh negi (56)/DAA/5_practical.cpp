#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n; 
        vector<int> arr(n); 
        for (int i = 0; i < n; i++) { 
            cin >> arr[i]; 
        } 
        
        bool found = false;
        for (int k = 2; k < n; k++) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (arr[i] + arr[j] == arr[k]) {
                    cout << i << " " << j << " " << k << endl;
                    found = true;
                    i++; j--;
                } else if (arr[i] + arr[j] < arr[k]) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        
        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0; 
}
