/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'


void solve() {
    int n, l, r ; cin >> n >> l >> r ;
    vector <ll> arr ;

    for(int i=0; i<n; i++) {
        int a ; cin >> a ;
        arr.pb(a) ;
    }
    sort(arr.begin(), arr.end()) ;

    ll total = 0 ;

    for(int i=1; i<n ;i++) {
        if(arr[i] > r) continue ;

        ll p1 = lower_bound(arr.begin(), arr.end(), l - arr[i]) - arr.begin();
        ll p2 = upper_bound(arr.begin(), arr.end(), r - arr[i]) - arr.begin();
        p2 -= 1 ;
        p2 = min(p2, (ll)i - 1);
        ll df = p2 - p1 + 1;
        if(p2 < 0 || p1 < 0 || p1 > p2) df = 0 ;
        total += df ;

    }
    cout << total << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int test = 1, no = 0;
    cin >> test ;
    while(test--) {
        solve();
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;
template <typename PB>
using ordered_set = tree<PB,null_type,less_equal<PB>,rb_tree_tag,tree_order_statistics_node_update> ;

void solve() {
    int n, l, r ; cin >> n >> l >> r ;
    ordered_set<int> st ;
    ll arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i] ;
    }
    st.insert(arr[0]);
    ll total = 0 ;
    for(int i=1; i<n; i++) {
        ll mn = l - arr[i];
        ll mx = r - arr[i];
        total += st.order_of_key(mx + 1) - st.order_of_key(mn);
        st.insert(arr[i]);
    }
    cout << total << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int test = 1, no = 0;
    cin >> test ;
    while(test--) {
        solve();
    }
    return 0;
}