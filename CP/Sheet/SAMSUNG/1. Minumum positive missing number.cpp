
/***
Question: You are given an unsorted array of positive and negative integer. You have to
find out the minimum positive Integer which is missing in the array.

Example: You have an array of 5 integer like [5, -10, 3, -2, 1] and the minimum missing
positive number is 2. So, the answer is 2.

***/

/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

int missingMinPosNum(int arr[], int sz) {
    if(sz == 0) return 1;

    for(int i = 0; i < sz; i++) {
        if(abs(arr[i]) - 1 < sz && arr[abs(arr[i]) - 1] > 0) {
            arr[abs(arr[i]) - 1] = - arr[abs(arr[i]) - 1];
        }
    }

    for(int i = 0; i < sz; i++) {
        if(arr[i] > 0) {
            return i + 1 ;
        }
    }

    return sz + 1 ;
}

void solve() {

    int n ; cin >> n ;
    int arr[n + 5] ;
    for(int i = 0; i < n ; i++) {
        cin >> arr[i] ;
    }

    int it = 0, posFirstInd = 0 ;
    while(it < n) {
        if(arr[it] <= 0) {
            int temp = arr[it] ;
            arr[it] = arr[posFirstInd] ;
            arr[posFirstInd] = temp ;
            posFirstInd++;
        }
        it++;
    }

    for(int i=posFirstInd; i<n; i++) cout << arr[i] << " " ;
    cout << endl;

    int ans = missingMinPosNum(arr + posFirstInd, n - posFirstInd) ;
    cout << ans << endl;
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


6
2 -1 1 4 -3 2
*/
