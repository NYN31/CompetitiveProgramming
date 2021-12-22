/*
https://codeforces.com/contest/1249/problem/B2
https://codeforces.com/contest/177/problem/C2
https://codeforces.com/contest/445/problem/B
https://codeforces.com/contest/25/problem/D
https://codeforces.com/contest/109/problem/C
https://codeforces.com/contest/1167/problem/C
https://codeforces.com/contest/791/problem/B
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 100

int parent[MX];
int rankParent[MX];

void initializeSet(int n)
{
    for(int i = 0; i<n; i++)
    {
        parent[i] = i;
        rankParent[i] = 0;
    }
}
int Find(int x)
{
    if(x != parent[x])
        return parent[x] = Find(parent[x]);
    else
        return x;
}
void Union(int a, int b)
{
    int px = Find(a);
    int py = Find(b);
    if(px == py)
        return;
    if(rankParent[px] < rankParent[py])
        parent[px] = py;
    else if(rankParent[px] > rankParent[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rankParent[px]++;
    }
}
int main()
{
    int n;
    cin >> n;
    initializeSet(n);

    Union(0, 1);
    Union(4, 2);
    Union(3, 1);
    Union(0, 3);
    Union(0, 4);

    for(int i = 0; i<n; i++)
        cout << "Node is " << i << " parent is " << parent[i] << " rank is " << rankParent[i] << endl;
    cout << endl;

    return 0;
}
/*
10
0 1 2 3 4 5 6 7 8 9
*/


/*
int par[sz];
int Rank[sz];
int ans[sz];

int Find(int x)
{
    if(x != par[x]) return par[x] = Find(par[x]);
    else return x;
}
void Union(int a, int b)
{
    int x = Find(a);
    int y = Find(b);
    if(x == y)
        return;
    if(Rank[x] < Rank[y])
        par[x] = y,Rank[Find(y)]++;
    else if(Rank[x] > Rank[y])
        par[y] = x,Rank[Find(x)]++;
    else {
        par[y] = x;
        Rank[x]++;
    }
}

void Set(int n){
    for(int i=1;i<=n;i++)
        par[i]=i,Rank[i]=1;
}

int Find(int x){
    if(x!=par[x]) return par[x]=Find(par[x]);
    else return x;
}

void Union(int a,int b){
    int i=Find(a),j=Find(b);
    if(i==j){
        cout<<"Cycle Detected"<<endl;
        return;
    }
    par[j]=i;
}




int par[MX];
int Size[MX];

void Set(int n){
    for(int i=1;i<=n;i++){
        par[i]=i;
        Size[i]=1;
    }
}
int Find(int x){
    if(x!=par[x]) return par[x]=Find(par[x]);
    else return x;
}
void Union(int a,int b){
    int i=Find(a),j=Find(b);
    if(i==j) return;
    if(Size[i]>Size[j]) swap(i,j);
    par[i]=j;
    Size[j]+=Size[i];
}


*/
