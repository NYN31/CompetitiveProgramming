#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
	int n ; cin >> n;
	if(n < 4) {
		cout << -1 << endl;
		return ;
	}
	deque <int > dq {3, 1, 4, 2} ;
	for(int i=5; i<=n; i++) {
		if(i&1) dq.push_front(i) ;
		else dq.push_back(i) ;
	}
	while(!dq.empty()) {
		int u = dq.front() ;
		dq.pop_front() ;
		cout << u << " " ;
	}
	cout << endl;
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