#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

int no = 0 ;

void solve() {
        ll l, r, s ; cin >> l >> r >> s ;
        set <int> leju, rony, sujon, all ;
        for(int i=0; i<l; i++) {
                int a ; cin >> a ; leju.insert(a) ; all.insert(a) ;
        }
        for(int i=0; i<r; i++) {
                int a ; cin >> a ; rony.insert(a) ; all.insert(a) ;
        }
        for(int i=0; i<s; i++) {
                int a ; cin >> a ; sujon.insert(a) ; all.insert(a) ;
        }
        ll l1, l2, r1, r2, s1, s2 ;
        l1 = l2 = r1 = r2 = s1 = s2 = 0 ;
        map<ll, ll> taken ;
        for(auto x : leju) {
                if(rony.find(x)==rony.end() && sujon.find(x)==sujon.end()) l1++ ;
        }
        for(auto x : rony) {
                if(leju.find(x)==leju.end() && sujon.find(x)==sujon.end()) r1++ ;
        }
        for(auto x: sujon) {
                if(rony.find(x)==rony.end() && leju.find(x)==leju.end()) s1++ ;
        }
        for(auto x: all) {
                if(leju.find(x) == leju.end() && rony.find(x) != rony.end() && sujon.find(x) != sujon.end()) l2++ ;
                if(leju.find(x) != leju.end() && rony.find(x) == rony.end() && sujon.find(x) != sujon.end()) r2++ ;
                if(leju.find(x) != leju.end() && rony.find(x) != rony.end() && sujon.find(x) == sujon.end()) s2++ ;
        }
        cout << "Case #" << ++no << ":" << nl ;
        cout << l1 << " " << l2 << nl ;
        cout << r1 << " " << r2 << nl ;
        cout << s1 << " " << s2 << nl ;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int t = 1, no = 0;
        cin >> t ;
        while(t--) {
                solve();
        }
        return 0;
}
