#include<bits/stdc++.h>
using namespace std;
int c=0;
void addEdge(vector<int> *p,int m,int n)
{
    p[m-1].push_back(n-1);
}
void DFS(vector<int> *a,int i,int *visited,int *rec)
{
rec[i]=1;
 vector<int>::iterator p;
for(p=a[i].begin();p<a[i].end();p++)
{
    if(rec[(*p)]==0&&visited[(*p)]==0)
        DFS(a,*p,visited,rec);
    else if(rec[(*p)]==1&&visited[(*p)]==0)
          c=1;
    else
        continue;
}
     rec[i]=0;
    visited[i]=1;

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
    int rec[v]={0};
for(int i=0;i<v;i++)
{
  if(visited[i]==0)
        DFS(a,i,visited,rec);

}
cout<<c<<endl;
}
