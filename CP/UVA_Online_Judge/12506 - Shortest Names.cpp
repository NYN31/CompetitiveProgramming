/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lm = 1000005 ;
int idx = 0, n ;
int trie[lm + 2][30];
int cnt[lm + 2] ;
bool flag[lm + 2] ;

void add(string str) {
    int u = 0 ;
    for(int i = 0; i < str.size(); i++) {
        int d = str[i] - 'a' ;
        if(!trie[u][d]) trie[u][d] = ++idx ;
        u = trie[u][d] ;
        cnt[u] += 1 ;
    }
    flag[u] = true ;
}

ll dfs(int u, int c = 0) {
    if(cnt[u] == 1) return c ;
    ll ans = 0 ;
    for(int i = 0; i < 26; i++) {
        int v = trie[u][i] ;
        if(v > 0) ans += dfs(v, c + 1) ;
    }
    return ans ;
}

void reset() {
    idx=0;
    memset(trie, 0, sizeof trie);
    memset(flag, false, sizeof flag);
    memset(cnt, 0, sizeof cnt);
}

void solve() {
    reset() ;
    cin >> n ;
    for(int i = 0; i < n ; i++) {
        string s ; cin >> s ;
        add(s) ;
    }

    ll ans = dfs(0) ;
    cout << ans << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int test = 1, no = 0;
    cin >> test ;
    while(test--) {
        solve();
    }
    return 0;
}

