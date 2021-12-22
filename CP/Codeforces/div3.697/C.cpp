/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

void solve() {
      int a, b, k ; cin >> a >> b >> k ;
      vector <ll> arr(k), brr(k) ;
      for(int i=0; i<k; i++) cin >> arr[i] ;
      for(int i=0; i<k; i++) cin >> brr[i] ;

      map <pair<ll, ll>, ll> mp ;
      mp[ {arr[0], brr[0]} ] = 1 ;
      ll arr_save[a+5] = { 0 }, brr_save[b+5] = { 0 } ;
      arr_save[arr[0]] = 1 , brr_save[brr[0]] = 1 ;
      ll ans = 0 ;
      for(int i=1; i<k; i++) {
            ans += (i - arr_save[arr[i]] - brr_save[brr[i]] + mp[ {arr[i], brr[i]} ]) ;
            arr_save[arr[i]] += 1 ;
            brr_save[brr[i]] += 1 ;
            mp[ {arr[i], brr[i]} ] += 1 ;
      }
      cout << ans << nl ;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int tt = 1, no = 0;
        cin >> tt ;
        while(tt--) {
                solve();
        }
        return 0;
}
