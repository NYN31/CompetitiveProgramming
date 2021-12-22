#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	string str, wtr; int n ;
	cin >> str >> n;
	int len = str.size() ;

	for(int i=1; i<=len; i++) wtr.pb('1') ; 
	for(int i=0; i<str.size(); i++) {
		int x = i-n;
		int y = i+n;
		if(str[i] == '0') {
			if(x >= 0) wtr[x] = '0' ;
			if(y < len) wtr[y] = '0' ;
		}
	}
	int ans = 1;
	for(int i=0; i<str.size(); i++) {
		int x = i-n;
		int y = i+n;
		int ok = 0;
		if(str[i] == '1') {
			if(x >= 0 && wtr[x] == '1') ok = 1;
			if(y < len && wtr[y] == '1') ok = 1;
			ans &= ok ;
		}
		if(ans == 0) break;
	}


	if( ans ) cout<<wtr<<endl;
	else cout<<-1<<endl;
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