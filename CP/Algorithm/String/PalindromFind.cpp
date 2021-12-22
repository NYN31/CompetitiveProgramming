/***
      You are given a string and some query and each query has two more integer
      which is the range of given string. More formally you are given a range of
      string index, and you have to find out the substring is palindrome or not
      palindrome.
***/

/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const ll lm = 1e5 + 5, B1 = 26, mod1 = 1979339339;
string s ;
ll prefHash[lm + 2], suffHash[lm + 2], po[lm + 2];

void getHash() {
      ll h = 0 ;
      for(int i=0; i<s.size(); i++) {
            h = ((h * B1) + s[i]) % mod1 ;
            prefHash[i] = h ;
      }
      h = 0 ;
      for(int i=s.size()-1; i>=0; --i) {
            h = ((h * B1) + s[i]) % mod1 ;
            suffHash[i] = h ;
      }
      po[0] = 1 ;
      for(int i=1; i<=s.size(); i++) {
            po[i] = (po[i - 1] * B1) % mod1;
      }
}

bool check(int b, int e) {
      ll hf = prefHash[e];
      if(b > 0) {
            hf = hf - (prefHash[b - 1] * po[e - b + 1]);
            hf %= mod1 ;
            if(hf < 0) hf += mod1 ;
      }
      ll hb = suffHash[b];
      if(e < s.size() - 1) {
            hb = hb - (suffHash[e + 1] * po[e - b + 1]) ;
            hb %= mod1 ;
            if(hb < 0) hb += mod1 ;
      }

      cout << hb << " " << hf << endl ;
      return hb == hf ;
}

void solve() {
      cin >> s ;
      getHash() ;
      int q ; cin >> q ;
      while(q--) {
            int l, r ; cin >> l >> r ;
            bool ans = check(l, r) ;
            if(ans) cout << "YES" << endl ;
            else cout << "NO" << endl ;
      }
}

int main() {
      ios::sync_with_stdio(false);
      cin.tie(0), cout.tie(0);
      int tt = 1, no = 0;
      //cin >> tt ;
      while(tt--) {
            solve();
      }
      return 0;
}

