#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back

vector <int> divi ;

void divisors(int n) {
    for(int i=1; i*i<=n; i++) {
        if(n % i != 0) continue ;
        if(n / i == i) divi.pb(i) ;
        else divi.pb(i), divi.pb(n / i) ;
    }
}

void solve() {
    int n ; cin >> n;
    int num = n;
    int arrn[15] = { 0 } ;
    while(num) {
        arrn[num % 10] = 1;
        num /= 10 ;
    }
    divisors(n) ;
    int cnt = 0;
    for(int i=0; i<divi.size(); i++) {
        ll val = divi[i] ;
        while(val) {
            if(arrn[val % 10]) {
                cnt += 1;
                break ;
            }
            val /= 10 ;
        }
    }
    cout << cnt << '\n' ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
