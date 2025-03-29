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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(v1[j]>v1[j+1])
            {
                int temp=v1[j];
                v1[j]=v1[j+1];
                v1[j+1]=temp;
            }
        }
    }   
    cout<<"Array After Sorting: ";
    for(int i=0;i<n;i++)
    {   
        cout<<v1[i]<<" ";
    }
}