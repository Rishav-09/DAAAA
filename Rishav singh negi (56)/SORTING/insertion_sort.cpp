#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Size Of Array :";
    cin>>n;
    vector<int>v1(n);
    cout<<"Enter Elements Of Array :";
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    for(int i=1;i<n;i++)
    {
        int prev=i-1;
        int curr=v1[i];
        while(0<=prev && v1[prev]>curr)
        {
            v1[prev+1]=v1[prev];
            prev--;
        }
        v1[prev+1]=curr;
    }
    cout<<"Array after Sorting: ";
    for(int i=0;i<n;i++)
    {
        cout<<v1[i];
    }

}