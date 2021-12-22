const int lm = 1000005 ;
int idx = 0, n ;
int trie[lm + 2][30];
int cnt[lm + 2] ;
bool flag[lm + 2] ;

class Trie {
    public:
    Trie() {
        idx = 0;
        memset(trie, 0, sizeof trie);
        memset(flag, false, sizeof flag);
        memset(cnt, 0, sizeof cnt);
    }
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
    bool search(string str) {
        int u = 0, v;
        for(int i = 0; i < str.size(); i++) {
            v = trie[u][str[i] - 'a'] ;
            if(v <= 0) return false ;
            u = v ;
        }
        return flag[v] ;
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
        // same as constructor
    }
};