/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

void solve() {
      int n ;
      while(cin >> n && n != 0) {
            vector <int> arr(n) ;
            for(int i=0; i<n; i++) cin >> arr[i] ;
            int com_fact = 0, tot_pair = 0;
            for(int i=0; i<n-1; i++) {
                  for(int j=i+1; j<n; j++)  {
                        if(__gcd(arr[i], arr[j]) == 1) {
                              com_fact += 1 ;
                        }
                        tot_pair += 1 ;
                  }
            }

            if(com_fact > 0) {
                  double x = (tot_pair * 6.0) / com_fact ;
                  x = sqrt(x) ;
                  cout << fixed << setprecision(6) << x << nl ;
            } else cout << "No estimate for this data set." << nl ;
      }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int tt = 1, no = 0;
        //cin >> tt ;
        //while(tt--) {
                solve();
        //}
        return 0;
}
