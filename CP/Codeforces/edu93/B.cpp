#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	string str ; cin >> str ;
	vector <int> arr ;
	int cnt = 0, total_one = 0;
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '1') {
			cnt += 1;
		}
		else if(cnt > 0 && str[i] == '0') {
			arr.pb(cnt) ;
			cnt = 0;
		} 
	}
	if(cnt > 0) arr.pb(cnt) ;
	sort(arr.rbegin(), arr.rend()) ;
	for(int i=0; i<arr.size(); i++) {
		if(i&1) continue ;
		total_one += arr[i] ;
	}
	cout << total_one << endl;
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