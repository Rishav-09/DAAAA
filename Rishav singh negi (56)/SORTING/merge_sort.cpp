#include<bits/stdc++.h>
using namespace std;
void mergesort(vector<int>&v1,int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    vector<int>temp(high+1);
    while(i<=mid && j<=high)
    {
        if(v1[i]<v1[j])
        {
            temp[k]=v1[i];
            i++;
            k++;
        }
        else{
            temp[k]=v1[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=v1[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=v1[j];
        j++;
        k++;
    }
    for(int i=0;i<temp.size();i++)
    {
        v1[low+i]=temp[i];
    }
}
void divide(vector<int>&v1,int low,int high)
{
    int mid;
    mid=low+(high-low)/2;
    if(low<high)
    {
        divide(v1,low,mid);
        divide(v1,mid+1,high);
        mergesort(v1,low,mid,high);
    }
}
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
    divide(v1,0,n-1);
    cout<<"Array After Sorting: ";
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
}
