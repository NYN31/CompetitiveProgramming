// Using Disjoint Set Union-Find Algorithm
// UVA 459

#include<bits/stdc++.h>
using namespace std;
int parent[1005];
int rankParent[1005];

void makeSet(int n)
{
    for(int i = 0; i<n; i++){
        parent[i] = i;
        rankParent[i] = 0;
    }
}
int Find(int x)
{
    if(x != parent[x])
        return parent[x] = Find(parent[x]);
    else return x;
}
void Union(int a, int b)
{
    int px = Find(a);
    int py = Find(b);
    parent[py] = px;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        char ch1; int n, count = 0;
        string s;
        cin >> ch1;
        n = ch1-'A' +1;
        makeSet(n);
        cin.ignore();
        while(getline(cin,s))
        {
            if(s.size() == 0)
                break;
            int a = s[0]-'A';
            int b = s[1]-'A';
            Union(a, b);
        }
        for(int i = 0; i<n; i++)
            if(parent[i] == i)
                count++;
        cout << count << endl;
		if(T)
			printf("\n");
    }
    return 0;
}
/*
1
E
AB
CE
DB
EC
*/
