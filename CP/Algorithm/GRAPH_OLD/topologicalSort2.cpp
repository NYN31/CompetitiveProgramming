//Using BFS
/*A Directed Acyclic Graph (DAG) G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
That means, the graph has no cycle.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector<int>order;
int in_degree[100];
int v, e;
void topologicalSort()
{
    for(int u=0;u<v;u++){
        for(int i=0;i<adj[u].size();i++){
            in_degree[adj[u][i]]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }

    int cnt=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        order.push_back(u);
        for(int i=0;i<adj[u].size();i++){
            --in_degree[adj[u][i]]; //Indegree of all vertixes would be zero. if any one remains >0, that means there exits cycle
            if(in_degree[adj[u][i]]==0){
                q.push(adj[u][i]);
            }
        }
        cnt++;
    }

    if(cnt!=v) cout<<"There exits a cycle in the Graph"<<endl;
    for(int i=0;i<order.size();i++)
        cout<<order[i]<<" ";
    cout<<endl;
}
int main()
{

    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    topologicalSort();
    return 0;
}
/*
6 6
5 2
5 0
4 0
4 1
2 3
3 1
*/
