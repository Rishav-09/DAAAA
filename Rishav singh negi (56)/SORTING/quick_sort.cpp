#include<bits/stdc++.h>

using namespace std;

int partion(vector<int>&v1, int start,int end)
{
    int idx=start-1;
    int pivot=v1[end];
    for(int i=start;i<end;i++)
    { 
        if(v1[i]<=pivot)
        {
            idx++;
            swap(v1[i],v1[idx]);
        }
    }
    idx++;
    swap(v1[idx],v1[end]);
    return idx;
}

void quicksort(vector<int>&v1,int start, int end){
    int pivot;
    if(start<end)
    {
        pivot=partion(v1, start, end);
        quicksort(v1, start, pivot-1);
        quicksort(v1,pivot+1,end);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v1(n);
    cout<<"Enter Element of Array: ";
    for(int i=0;i<n;i++)
    {   
        cin>>v1[i];
    }
    quicksort(v1,0,n-1);
    cout<<"Array after sorting";
    for(int i=0;i<n;i++)
    {
        cout<<v1[i]<<" ";
    }
}