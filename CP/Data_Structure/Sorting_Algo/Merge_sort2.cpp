/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lm = 2000100;
int arr[lm + 2], temp[lm + 2];

void merge_sort(int lo, int hi) {
    if(lo == hi) return ;
    int mid = lo + (hi - lo) / 2 ;

    merge_sort(lo, mid);
    merge_sort(mid + 1, hi);

    int i, j, k ;
    for(i = lo, j = mid + 1, k = lo; k <= hi; k++) {
        if(i == mid + 1) temp[k] = arr[j++];
        else if(j == hi + 1) temp[k] = arr[i++];
        else if(arr[i] < arr[j]) temp[k] = arr[i++];
        else temp[k] = arr[j++];
    }
    for(i=lo; i<=hi; i++) arr[i] = temp[i];
}

void solve() {
    int n ; cin >> n ;
    for(int i=1; i<=n; i++) cin >> arr[i] ;
    merge_sort(1, n) ;
    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << endl ;
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

