
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

void solve() {
    int n, c0, c1, h ;
    string str ;
    cin >> n >> c0 >> c1 >> h ;
    cin >> str ;
    int mn = 1e9, zero = 0, one = 0 ;
    for(int j=0; j<str.size(); j++) {
        if(str[j] == '1') one += 1 ;
        else zero += 1 ;
    }
    for(int i=0; i<=n; i++) {
        int z = i, o = n - i ;
        int dif = abs(z - zero) ;
        int ans = (z * c0) + (o * c1) + dif * h ;
        mn = min(ans, mn) ;

    }
    cout << mn << endl ;
}

int main() {
    int t = 1, no = 0;
    scanf("%d", &t) ;
    while(t--) {
        solve();
    }
    return 0;
}
