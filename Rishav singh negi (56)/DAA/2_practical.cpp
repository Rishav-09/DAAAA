#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
    int t;
    cout << "ENTER NUMBER OF TEST CASES: ";
    cin >> t;
    
    while (t--) {
        int n; 
        cout << "ENTER SIZE OF ARRAY: "; 
        cin >> n; 
        vector<int> v1(n); 
        cout << "ENTER ELEMENT OF VECTOR: "; 
        for (int i = 0; i < n; i++) { 
            cin >> v1[i]; 
        } 
        cout << "ENTER ELEMENT TO SEARCH: "; 
        int target; 
        cin >> target; 
        
        int low = 0, high = n - 1; 
        int count = 1; 
        while (low <= high) { 
            int mid = (low + high) / 2; 
            count++; 
            if (v1[mid] == target) { 
                cout << "Element found " << count << endl; 
                break; 
            } else if (v1[mid] < target) { 
                low = mid + 1; 
            } else { 
                high = mid - 1; 
            } 
        } 
        if (low > high) {
            cout << "NOT PRESENT" << endl;
        }
    }
    return 0; 
}
