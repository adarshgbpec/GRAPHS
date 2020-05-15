#include<bits/stdc++.h>
using namespace std;
int c=0;
stack<int> s;
void addEdge(vector<int> *a,vector<int> *b ,int u,int v)
{
    a[u-1].push_back(v-1);
    b[v-1].push_back(u-1);
}
void SecondDFS(vector<int> *c,int i,int *visited)
{
visited[i]=1;

vector<int>::iterator ptr;
for(ptr=c[i].begin();ptr<c[i].end();ptr++)
    {
        if(visited[(*ptr)]==0){
            SecondDFS(c,*ptr,visited);

        }

    }
}
void DFS(vector <int> *c,int *visited,int i)
{
    visited[i]=1;
    vector<int>::iterator ptr;
    for(ptr=c[i].begin();ptr<c[i].end();ptr++)
    {
        if(visited[(*ptr)]==0){
            DFS(c,visited,*ptr);
              s.push(*ptr);
        }

    }
}
int main()
{
     int v,n,m,e;
    cin>>v>>e;
    vector<int> a[v];
    vector<int> b[v];
    vector<int>::iterator p;
    for(int i=0;i<e;i++){
        cin>>m>>n;
        addEdge(a,b,m,n);
    }

    int visited[v]={0};


   for(int i=0;i<v;i++)
    {
      if(visited[i]==0)
        {
        DFS(b,visited,i);
        s.push(i);
        }
    }
    int k;
    int visited_new[v]={0};
    while(!s.empty())
    {
       if(visited_new[s.top()]==0)
       {
         SecondDFS(a,s.top(),visited_new);
         c+=1;
         s.pop();

       }
       else
        s.pop();
    }
   cout<<c<<endl;
}
