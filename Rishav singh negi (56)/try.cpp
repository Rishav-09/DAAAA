#include<bits/stdc++.h>
using namespace std;
void print(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
void bublesort(vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size()-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
            }            
        }   
    }
}
void insertsort(vector<int>&v)
{
    int n=v.size();
    for(int i=1;i<n;i++)
    {
        int prev=i-1;
        int cur=v[i];   
        while(prev>=0 && v[prev]>cur)
        {
            v[prev+1]=v[prev];
            prev--;
        }
        v[prev+1]=cur; 
    }
}
void selectionsort(vector<int>&v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[min])
            {
                min=j;
            }
        }
        swap(v[i],v[min]);
    }
}
void countsort(vector<int>v)
{
    int MAXE=*max_element(v.begin(),v.end());
    vector<int>count(MAXE+1,0);
    for(int i=0;i<v.size();i++)
    {
        count[v[i]]++;
    }
    for(int i=0;i<MAXE;i++)
    {
        count[i+1]+=count[i];
    }
    vector<int>final(v.size());
    int idx=v.size()-1;
    for(int i=0;i<v.size();i++)
    {
        final[count[v[idx]]--]=v[idx];
        idx--;
    }
    for(int i=0;i<final.size();i++)
    {
        cout<<final[i]<<" ";
    }
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
    // bublesort(v);
    // insertsort(v);
    // selectionsort(v);
    // print(v);
    // cout<<endl;
    countsort(v);
}