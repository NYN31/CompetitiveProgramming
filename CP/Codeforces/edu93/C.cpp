#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll n, ans = 0 , val = 0; cin >> n ;
	string str ; cin >> str ;
	map < int, int > mp ;
	mp[ 0 ] = 1;
	for(int i=0; i<n; i++) {
		ans += (str[i] - '0' - 1) ;
		if(mp[ ans ] > 0)
			val += mp[ ans ] ; 
		mp[ ans ] += 1;
	}
	cout<< val << endl;
}
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}