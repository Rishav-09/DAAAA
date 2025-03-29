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
        int place = 1; 
        for (int i = 0; i < n; i++) { 
            if (v1[i] == target) { 
                cout << "Present " << place << endl; 
                break; 
            } else { 
                place++; 
            } 
        } 
        if (place > n) {
            cout << "NOT PRESENT" << endl;
        }
    }
    return 0; 
}
