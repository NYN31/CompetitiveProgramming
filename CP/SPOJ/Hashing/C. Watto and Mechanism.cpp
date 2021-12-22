/*
        Codeforces problem
        problem link : https://codeforces.com/contest/514/problem/C
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
ll const B1 = 19;
ll const B2 = 47;
ll const mod1 = 1979339339;
ll const mod2 = 2513475829;
 
ll getHash(string str, ll mod, ll B) {
    ll h = 0;
    for(int i=0;i<str.size();i++) {
        h = h*B + str[i];
        h %= mod;
    }
    return h;
}
 
 
int main() {
    BeatMeScanf;
    int n, m; cin>>n>>m;
    vector<ll>vec1,vec2;
    for(int i=0;i<n;i++) {
        string str; cin>>str;
        ll hs1 = getHash(str, mod1, B1);
        ll hs2 = getHash(str, mod2, B2);
        vec1.pb(hs1);
        vec2.pb(hs2);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    for(int i=0;i<m;i++) {
        string str; cin>>str;
        ll hs1 = getHash(str, mod1, B1);
        ll hs2 = getHash(str, mod2, B2);
        ll b1 = 1, b2 = 1; bool flag = true;
        for(int j=str.size()-1; j>=0 && flag;j--) {
            for(int ch = 0; ch <= 2 && flag; ch++) {
                if(str[j] == (char)(ch+'a')) continue;
                ll val1 = hs1 - (str[j] * b1);
                ll val2 = hs2 - (str[j] * b2);
                val1 = (val1 % mod1 + mod1) % mod1;
                val2 = (val2 % mod2 + mod2) % mod2;
                val1 = (val1 + (ch + 'a') * b1 ) % mod1;
                val2 = (val2 + (ch + 'a') * b2 ) % mod2;
                ll pos1 = lower_bound(vec1.begin(), vec1.end(), val1) - vec1.begin();
                ll pos2 = lower_bound(vec2.begin(), vec2.end(), val2) - vec2.begin();
                if(pos1 == n || pos2 == n || vec1[pos1] != val1 || vec2[pos2] != val2) continue;
                flag = false;
            }
            b1 = (b1 * B1) % mod1;
            b2 = (b2 * B2) % mod2;
        }
        if(!flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
