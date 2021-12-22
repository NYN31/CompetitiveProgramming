#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
	string str1, str2 ; cin>>str1>>str2;
	int mn = 1e9, ln = str2.size();
	for(int i=0;i<str1.size()-str2.size()+1;i++) {
		int k = 0, cnt = 0;
		for(int j=i;j<i+ln;j++) {
			if(str1[j] != str2[k++]) cnt += 1;
		}
		mn = min(mn, cnt) ;
	}
	cout<<mn<<endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}