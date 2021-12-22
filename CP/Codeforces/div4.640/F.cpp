#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back

inline void comb1(int a, int b, int c) {
	string str1="", str2="", str3="" ;
	for(int i=0; i<=c; i++) str3.pb('1');
	cout << str1 + str2 + str3 << endl;
}

inline void comb2(int a, int b, int c) {
	string str1="", str2="", str3="" ;
	for(int i=0; i<=b; i++) {
		if(i&1) str2.pb('0') ;
		else str2.pb('1');
	}
	cout << str1 + str2 + str3 << endl;
}

inline void comb3(int a, int b, int c) {
	string str1="", str2="", str3="" ;
	for(int i=0; i<b; i++) {
		if(i&1) str2.pb('0') ;
		else str2.pb('1') ;
	}
	for(int i=0; i<c; i++) str3.pb('1') ;
	if(!(b&1)) str3.pb('1') ;
	if(b&1)str3.pb('0') ;
	cout << str1 + str2 + str3 << endl;
}
inline void comb4(int a, int b, int c) {
	string str1="", str2="", str3="" ;
	for(int i=0; i<=a; i++) str1.pb('0');
	cout << str1 + str2 + str3 << endl;
}

inline void comb5(int a, int b, int c) {
	string str1="", str2="", str3="" ;
	for(int i=0; i<a; i++) str1.pb('0') ;
	for(int i=0; i<=c; i++) str3.pb('1') ;
	cout << str1 + str2 + str3 << endl;
}
inline void comb6(int a, int b, int c) {
	string str1="", str2="", str3="" ;
	for(int i=0; i<=a; i++) str1.pb('0');
	for(int i=0; i<b; i++) {
		if(i&1) str2.pb('0') ;
		else str2.pb('1') ;
	}
	cout << str1 + str2 + str3 << endl;
}

void comb7(int a, int b, int c) {
	string str1="", str2="", str3="" ;
	for(int i=0; i<b-1; i++) {
		if(i%2==0) str2.pb('0') ;
		else str2.pb('1') ;
	}
	reverse(str2.begin(), str2.end()) ;
	for(int i=0; i<=c; i++) str3.pb('1') ;
	str3.pb('0') ;
	for(int i=1; i<=a; i++) str1.pb('0') ;
	cout << str2 + str3 + str1 << endl;
}

void solve() {
	int n1, n2, n3 ; cin >> n1 >> n2 >> n3 ;
	if(n1==0 && n2==0 && n3!=0) comb1(n1, n2, n3) ;
	else if(n1==0 && n2!=0 && n3==0) comb2(n1, n2, n3) ;
	else if(n1==0 && n2!=0 && n3!=0) comb3(n1, n2, n3) ;
	else if(n1!=0 && n2==0 && n3==0) comb4(n1, n2, n3) ;
	else if(n1!=0 && n2==0 && n3!=0) comb5(n1, n2, n3) ;
	else if(n1!=0 && n2!=0 && n3==0) comb6(n1, n2, n3) ;
	else if(n1!=0 && n2!=0 && n3!=0) comb7(n1, n2, n3) ;
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