#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

int no = 0 ;

void solve() {
        //HELLO
        bool flag = true ;
        for(int i=1; i<=13; i++) {
                ll a ; cin >> a ;
                if(a == 0) flag = false ;
        }
        if(flag) cout << "Set #" << ++no << ": " << "Yes" << nl ;
        else cout << "Set #" << ++no << ": " << "No" << nl ;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int t = 1;
        cin >> t ;
        while(t--) {
                solve();
        }
        return 0;
}
