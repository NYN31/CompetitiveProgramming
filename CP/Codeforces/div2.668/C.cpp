#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
	int n , k ; cin >> n >> k ;
	string str ; cin >> str ;
 
	string seg ;
	for(int i=0; i<k; i++) seg.pb(str[i]) ;
 
	bool flag = true ;
	for(int i=0; i<k && flag; i++) {
		for(int j=i+k; j<str.size() && flag; j+=k) {
			if(str[j] != seg[i] && (str[j] != '?' && seg[i] != '?')) {
				flag = false ;
				break ;
			}
			if(seg[i] == '?') seg[i] = str[j] ;
		}
	}
	int cnt[2] = { 0 } ;
	for(int i=0; i<k; i++) 
		if(seg[i] != '?')
			cnt[ seg[i] - '0' ] += 1;
	if(cnt[0] <= k/2 && cnt[1] <= k/2) flag = flag ;
	else flag = false ;
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
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