#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back


void solve() {
	int n; cin >> n;
	int fq[30] = {0} ;
	for(int i=1;i<=n;i++) {
		string str; cin >> str ;
		for(int j=0;j<str.size();j++) {
			fq[ str[j] - 'a'] += 1;
		}
	}
	for(int i=0;i<26;i++) {
		if(fq[i] % n != 0) {
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
	return ;
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