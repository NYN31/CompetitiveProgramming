#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

ll const mod = 1e9 + 7 ;

inline ll add(ll a, ll b) {
	return ((a + b) % mod + mod) % mod ;
}
inline ll mul(ll a, ll b) {
	return ((a * b) % mod + mod) % mod ;
}
inline ll nC2(ll n) {
	return add(n * (n + 1) / 2 , 0) ;
}

void solve() {
	string str ; cin >> str ;
	int n = str.size() ;
	vector <int> arr(n) ;
	for(int i=0; i<n; i++) arr[i] = str[n-i-1] - '0'; 

	ll total = 0 , tenValues = 0, tenPower = 1 , nC2s_value = n - 1, position = 1;
	for(auto dig : arr) {
		// Case 1: when digits are in fixed position
		total = add(total, mul(dig, mul(nC2(nC2s_value), tenPower))) ;
		// Case 2: when digits are'nt in fixed position
		total = add(total , mul(dig, tenValues));
		tenValues = add(tenValues, mul(position, tenPower)) ;
		tenPower = mul(tenPower, 10) ;
		nC2s_value -= 1 ;
		position += 1 ;
	}

	cout << total << '\n' ;
}  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

