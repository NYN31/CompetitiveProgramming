#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
int fq[8010] ;
int arr[8010] ;
 
void solve() {
	int n, cnt = 0, mx = 0; scanf("%d", &n) ;
	memset(fq, 0, sizeof fq) ;
	arr[0] = 0 ;
 	for(int i=1; i<=n; i++) {
		scanf("%d", &arr[i]) ;
		mx = max(mx, arr[i]) ;
		fq[ arr[i] ] += 1;
		arr[i] += arr[i-1] ;
	}
	for(int i=1; i<=n-1; i++) {
		for(int j=i+1; j<=n; j++) {
 			int val = arr[j] - arr[i-1] ;
 			if(val > mx) continue ;
			if( fq[val] > 0 ) {
				cnt += fq[val];
				fq[val] = 0 ;
			}
		}
	}
	printf("%d\n", cnt) ;
}
  
int main() {
    int t = 1, no = 0;
    scanf("%d", &t) ;
    while(t--) {
        solve();
    }
    return 0;
}