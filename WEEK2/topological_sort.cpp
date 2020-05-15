#include<bits/stdc++.h>
using namespace std;
stack<int> s;
void addEdge(vector<int> *p,int m,int n)
{
    p[m-1].push_back(n-1);
}
void DFS(vector<int> *a,int i,int *visited)
{
    visited[i]=1;
    vector<int>::iterator p;
    for(p=a[i].begin();p<a[i].end();p++)
    {
        if(visited[*p]==0)
            DFS(a,*p,visited);
    }
    s.push(i);
}
int main()
{
      int v,n,m,e;
    cin>>v>>e;
    vector<int> a[v];
    vector<int>::iterator p;
    for(int i=0;i<e;i++){
        cin>>m>>n;
        addEdge(a,m,n);
    }
    int visited[v]={0};
    for(int i=0;i<v;i++)
    {
     if(visited[i]==0)
            DFS(a,i,visited);
    }
    while(!s.empty())
    {
        cout<<(s.top()+1)<<' ';
        s.pop();
    }
}
