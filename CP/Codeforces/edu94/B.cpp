#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	ll my, frnd, ache1, ache2, w1, w2, ans = 0;
	cin >> my >> frnd ;
	cin >> ache1 >> ache2 ;
	cin >> w1 >> w2 ;

	if(w1 > w2) {
		swap(ache1, ache2) ;
		swap(w1, w2) ;
	}

	for(int a=0; a<=ache1; a++) {
		if(a * w1 > my) break ;

		ll leftmy = my - (a*w1) ;
		ll b = min(leftmy / w2, ache2) ;

		ll achecopy1 = ache1 - a ;
		ll achecopy2 = ache2 - b ;
		
		ll c = min(frnd / w1, achecopy1) ;
		ll leftfrnd = frnd - (c * w1) ;
		ll d = min(leftfrnd / w2, achecopy2) ;
		ans = max(ans, a+b+c+d) ;
	}
	cout<<ans<<endl;
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