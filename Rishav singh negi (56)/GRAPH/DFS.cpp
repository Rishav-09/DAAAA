#include <iostream>
using namespace std;
#include<vector>
#include<queue>
void BFS(vector<vector<int>>adjlist,int start,vector<int>&visted)
{
    queue<int>q;
    visted[start]=1;
    q.push(start);
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        cout<<s<<" ";
        for(int i=0;i<adjlist[s].size();i++)
        {
            int nbr=adjlist[s][i];
            if(visted[nbr]!=1)
            {
                q.push(nbr);
                visted[nbr]=1;
            }
        }
    }
}
void DFS(vector<vector<int>>adjlist,int start,vector<int>&visted)
{
    visted[start]=1;
    cout<<start;
    for(int i=0;i<adjlist[start].size();i++)
    {
        if(visted[adjlist[start][i]]!=1)
        {
            DFS(adjlist,adjlist[start][i],visted);
        }
    }
}

int main()
{
    int n,E;
    cin>>n;
    cin>>E;
    int U,V;
    vector<vector<int>>adjlist(n+1);
    for(int i=0;i<E;i++)
    {
        cin>>U>>V;
        adjlist[U].push_back(V);
    }
    vector<int>visted(n+1,0);
    // BFS(adjlist,0,visted);
    DFS(adjlist,0,visted);
    return 0;
}