/**
      USING DSU
**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lm = 1e3 + 5 ;
int par[lm + 1], sz[lm + 1] ;

void make_set(int n) {
      for(int i=0; i<n; i++) {
            par[i] = i ;
            sz[i] = 1 ;
      }
}

int find_set(int x) {
      if(x == par[x]) return x ;
      else return par[x] = find_set(par[x]) ;
}

void union_set(int x, int y) {
      int a = find_set(x) ;
      int b = find_set(y) ;
      if(a != b) {
            if(sz[a] < sz[b]) swap(a, b) ;
            par[b] = a ;
            sz[a] += sz[b] ;
      }
}

void solve() {
      char ch ; cin >> ch ;
      string str ; int n ;
      n = ch - 'A' + 1 ;
      cin.ignore() ;
      make_set(n) ;
      while(getline(cin, str)) {
            if(str.size() == 0) break ;
            int a, b ;
            a = str[0] - 'A' ;
            b = str[1] - 'A' ;
            union_set(a, b) ;
      }
      set <int> st ;
      for(int i=0; i<n; i++) {
            st.insert(find_set(i)) ;
      }
      cout << st.size() << nl ;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int tt = 1, no = 0;
        cin >> tt ;
        while(tt--) {
                solve();
                if(tt) cout << nl ;
        }
        return 0;
}



/**
      USING BFS
**/
vector <int> graph[1000];
int visited[1000];

void dfs(int s)
{
    visited[s] = 1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(int i = 0; i<graph[top].size(); i++)
        {
            int v = graph[top][i];
            if(visited[v] == -1)
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(visited, -1, sizeof(visited));
        char ch1; int n, count = 0;
        string s;
        cin >> ch1;
        n = ch1-'A' + 1;
        cin.ignore();
        while(getline(cin,s))
        {
            if(s.size() == 0)
                break;
            int a = s[0]-'A';
            int b = s[1]-'A';
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 0; i<n; i++)
        {
            if(visited[i] == -1)
            {
                count++; dfs(i);
            }
        }
        cout << count << endl;
		if(T)
			printf("\n");
		for(int i=0; i<n; i++)
			graph[i].clear();
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
