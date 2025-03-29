#include<bits/stdc++.h>
using namespace std;
void countsort(vector<int>&v,int exp)
{
    int freq[10]={0};
    for(int i=0;i<v.size();i++)
    {
        freq[(v[i]/exp)%10]++;
    }
    for(int j=8;j>=0;j--)
    {
        freq[j]+=freq[j+1];;
    }
    int n=v.size();
    vector<int>output(n);
    for(int i=0;i<n;i++)
    {
        output[--freq[(v[i]/exp)%10]]=v[i];
    }  
    for(int i=0;i<n;i++)
    {
        v[i]=output[i];
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    int exp=1;
    int maxi=*max_element(vec.begin(),vec.end());
    for(int i=exp;maxi/exp>0; exp*=10)
    {
        countsort(vec,exp);
    }
    for(int i=0;i<n;i++)
    {
        cout<<vec[i]<<" ";
    }


}