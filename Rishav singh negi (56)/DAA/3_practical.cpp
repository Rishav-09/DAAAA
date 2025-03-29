#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
    int t;
    cout << "ENTER NUMBER OF TEST CASES: ";
    cin >> t;
    
    while (t--) {
        int n; 
        cout << "Size of Array: "; 
        cin >> n; 
        vector<int> arr(n); 
        cout << "Enter Elements Of Array: "; 
        for (int i = 0; i < n; i++) { 
            cin >> arr[i]; 
        } 
        
        int key;
        cout << "Key: "; 
        cin >> key; 
        
        int prev = 0;
        int i = 0;
        while (i < n && arr[i] < key) {
            prev = i;
            i = i + 2;
        }
        int flag=0;
        for (int j = prev; j <= i && j < n; j++) {
                if (arr[j] == key) {
                    cout << "Element found" << endl;
                    flag=-1;
                    break;
                }
            }
        if(flag!=-1)
        {
            cout << "Element not found" << endl;
        }
    }
    return 0; 
}
