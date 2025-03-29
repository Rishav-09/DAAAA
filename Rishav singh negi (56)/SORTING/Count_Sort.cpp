#include<bits/stdc++.h>
using namespace std;
vector<int> countsort(vector<int>v)
{
    int MAXE=*max_element(v.begin(),v.end());
    vector<int>count(MAXE+1,0);
    for(int i=0;i<v.size();i++)
    {
        count[v[i]]++;
    }
    // for(int i=1;i<=MAXE;i++)
    // {
    //     count[i]=count[i]+count[i-1];
    // }
    for (int i = MAXE - 1; i >= 0; i--) { // Reverse cumulative sum
        count[i] += count[i + 1];
    }
    vector<int>final(v.size());
    int idx=v.size()-1;
    for(int i=0;i<v.size();i++) 
    {  
        final[--count[v[i]]] = v[i];  
    }

    return final;
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>v;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    v=countsort(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}