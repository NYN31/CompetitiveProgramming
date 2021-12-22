/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

void solve() {
      int n ; cin >> n ;
      string input ; cin >> input ;

      vector <int> arr[30] ;
      for(int i=0; i<input.size(); i++) {
            arr[input[i] - 'a' + 1].pb(i + 1) ;
      }

      int q ; cin >> q ;
      while(q--) {
            string query ; cin >> query ;
            int prev = -1 ;
            bool flag = true ;
            for(int i=0; i<query.size(); i++) {
                  char ch = query[i] ;
                  int val = ch - 'a' + 1 ;

                  if(prev != -1 && (query[i-1] - 'a' + 1) == val) prev += 1 ;
                  auto pos = lower_bound(arr[val].begin(), arr[val].end(), prev) - arr[val].begin() ;
                  if(pos < arr[val].size()) {
                        prev = arr[val][pos] ;
                  } else {
                        flag = false ;
                        break ;
                  }
            }
            if(flag) cout << "YES" << endl ;
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

