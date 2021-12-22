#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back


void solve() {
	int n, odd = 0, even = 0 ; cin >> n;
	vector <int> arr , od, ev;
	for(int i=0; i<2*n; i++) {
		int a ; cin >> a;
		arr.pb(a) ;
		if(a%2 == 1) odd++ ;
		else even++ ;
	}

	if(odd % 2 == 0) {
		if(odd > 0) odd -= 2 ;
		else even -= 2 ;
	}
	else if(odd % 2 == 1)
		odd -= 1, even -= 1;
	for(int i=0; i<arr.size(); i++) {
		if(arr[i]%2 == 0 && even) {
			ev.pb(i+1) ;
			even -= 1;
		}
		if(arr[i]%2 == 1 && odd) {
			od.pb(i+1) ;
			odd -= 1;
		}
	}
	for(int i=0; i<ev.size(); i+=2)
		cout << ev[i] << " " << ev[i+1] << endl;
	for(int i=0; i<od.size(); i+=2)
		cout << od[i] << " " << od[i+1] << endl;

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