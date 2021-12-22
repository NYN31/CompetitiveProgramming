

/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'
#define sz 20
#define inf 10000000

ll findSubarray(vector <ll> arr, int n) {
    unordered_map<ll, ll> frequency;

    frequency[0] = 1;
    ll tot = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        tot += arr[i];
        if(frequency.find(tot) != frequency.end()) {
            ans += frequency[tot];
        }
        frequency[tot] += 1;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector <ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << findSubarray(arr, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    int test = 1, no = 0;
    //cin >> test ;
    while(test--) {
        solve();
    }
    return 0;
}


/*
10
6 -1 -3 4 -2 2 4 6 -12 -7
ans = 4

6
0 0 5 5 0 0
ans = 6

30
6 -9 11 -10 -15 -14 18 20 -12 7 3 -7 -8 -9 20 -1 0 -6 4 18 -13 -10 -9 -6 -10 -9 -11 3 12 20
ans = 7
*/

