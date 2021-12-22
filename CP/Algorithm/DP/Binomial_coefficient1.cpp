#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll nCr[100][100];
ll prealoc(ll n, ll r)
{
    nCr[0][0] = 1;
    for(ll i = 0; i<=n; i++){
        for(ll j = 0; j<=n; j++){
            if(j>i) nCr[i][j] = 0;
            else if(j == i || j == 0) nCr[i][j] = 1;
            else nCr[i][j] = nCr[i-1][j]+nCr[i-1][j-1];
            cout << nCr[i][j] << " ";
        }
        cout << endl;
    }
    return nCr[n][r];
}

int main()
{
    ll n, r;
    cin >> n >> r;
    cout << prealoc(n,r) << endl;
    return 0;
}
