#include <bits/stdc++.h>
using namespace std;
//     20 
// 10      30 
// 40 50
class heap 
{
    public:
    int size;
    int n=0;
    vector<int> ar = vector<int>(100);
    heap(int n,int size)
    {
        this->n=n;
        this->size=size;
    }
 
    void insert(int no)
    {
        for(int i=0;i<no;i++)
        {
            size++;
            cin>>ar[size];    
        }
    }

    void print()
    {
        for(int i=0;i<=size;i++) cout<<ar[i]<<" ";
    }

    void heapify(int i)
    { 
        int c1=2*i+1;
        int c2=2*1+2;
        int max=ar[i];
        if(c1<n && ar[i]<ar[c1])
        {
            max=c1;
        }
        if(c2<n && ar[i]<ar[c2])
        {
            max=c2;
        }
        if(max!=ar[i])
        {
            swap(ar[max],ar[i]);
            heapify(max);
        }
    }
    
};
int main()
{
    heap p(100,-1);
    int n;
    cin>>n;
    p.insert(n);
    cout<<"After ";
    p.print();
    cout<<"Before";
    p.heapify(0);
    p.print();
    return 0;
}

 

