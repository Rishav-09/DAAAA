#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;
    vector<int>v1(n);
    cout<<"Enter Element of Array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    int k=1;
    int index=0;
    for(int i=0;i<n;i++)
    {   
        int min=v1[i];
        index=i;
        for(int j=i+1;j<n;j++)
        {
            if(v1[j]<min)
            {
                min=v1[j];
                index=j;
            }
        }
        if(index!=i)
        {
            swap(v1[index],v1[i]);
        }
    }
    cout<<"Array Element after swap: ";   
    for(int i=0;i<n;i++)
    {
        cout<<v1[i]<<" ";
    }

}