#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	int n ; cin >> n ;
	string str ; cin >> str ;
	int lstr = str.size() , idx1 = -1, idx2 = -1, f = 1;
	for(int i=lstr-1; i>=0; --i) {
		if(str[i] == '1' && f) continue ;
		f = 0 ;
		if(str[i] == '0') {
			idx2 = i ;
			break ;
		}
	}
	for(int i=0; i<lstr-1; i++) {
		if(str[i] == '1') {
			idx1 = i;
			break ;
		}
	}
	if(idx1 != -1 && idx2 != -1 && idx1 <= idx2) {
		string s1, s2 ;
		for(int i=0; i<idx1; i++) s1.pb(str[i]) ;
		for(int i=idx2; i<lstr; i++) s2.pb(str[i]) ;
		cout << s1 + s2 << endl ;
	}
	else cout << str << endl ;
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