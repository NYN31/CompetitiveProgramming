#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
	int n ; cin >> n; 
	string str ; cin >> str ; 

	if(n % 2 == 1) {
		bool flag = false ;
		for(int i=0; i<n; i++) {
			if(i%2 == 0 && (str[i]-'0')%2 == 1) {
				flag = true ;
				break ;
			}
		}
		if(flag) cout << 1 << endl ;
		else cout << 2 << endl ;
	}
	else {
		bool flag = false ;
		for(int i=0; i<n; i++) {
			if(i%2 == 1 && (str[i]-'0')%2 == 0) {
				flag = true ;
				break ;
			}
		}
		if(flag) cout << 2 << endl ;
		else cout << 1 << endl ;
	}

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

