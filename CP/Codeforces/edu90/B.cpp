#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
	string str ; cin >> str ;
	int one = 0, zero = 0 ;
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '1') one += 1 ;
		else zero += 1 ;
	}
	int mn = min(one, zero) ;
	if(mn % 2 == 0) cout << "NET" << endl ;
	else cout << "DA" << endl ;
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