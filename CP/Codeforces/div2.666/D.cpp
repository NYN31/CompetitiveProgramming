#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	int n; cin >> n;
	queue <int> qu ;
	int mx = 0, sum = 0;
	for(int i=1; i<=n; i++) {
		int a ; cin >> a ;
		qu.push(a) ;
		mx = max(mx, a) ;
		sum += a ;
	}
	if(mx-(sum-mx) > 0) {
		cout << "T" << endl ;
	}
	else {
		if(sum & 1) cout << 'T' << endl ;
		else cout << "HL" << endl ;
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


/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	int n; cin >> n;
	priority_queue <int> qu ;
	int mx = 0, sum = 0;
	for(int i=1; i<=n; i++) {
		int a ; cin >> a ;
		qu.push(a) ;
	}
	bool flag = false;
	while( true ) {
		int top1 = qu.top() ;
		qu.pop() ;
		top1 -= 1 ;
		if(qu.empty()) break ;
		int top2 = qu.top() ;
		qu.pop() ;
		top2 -= 1;
		if(top1 > 0) qu.push(top1) ;
		if(top2 > 0) qu.push(top2) ;
		if(qu.empty()) {
			flag = true ;
			break;
		}
	}
	if(!flag) cout << "T" << '\n' ;
	else cout << "HL" << '\n' ;
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
*/