#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[1000][1000];

ll nCr(ll n, ll r)
{
    if(r == 1) return n;
    if(r == n || r == 0) return 1;
    if(dp[n][r] != 0) return dp[n][r];
    return dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
}

int main()
{
    for(ll i = 0; i<1000; i++)
        for(ll j =0; j<1000; j++)
            dp[i][j] = 0;

    ll n, r;
    while(cin >> n >> r)
    {
        if(n == 0 && r == 0) break;
        cout << n << " things taken " << r << " at a time is " << nCr(n, r) << " exactly." << endl;
    }
    return 0;
}


///100 things taken 6 at a time is 1192052400 exactly.
/*#include<stdio.h>
long long nCr(long long n, long long r)
{
    if(n == r) return 1;
    else if(r == 1) return n;
    else
        return nCr(n-1, r-1) + nCr(n-1, r);
}
int main()
{
    long long n, r, res;
    while(scanf("%lld %lld", &n, &r))
    {
        if(n == 0 && r == 0) break;
        res = nCr(n, r);
        printf("%lld things taken %lld at a time is %lld exactly.\n", n, r, res);
    }
    return 0;
}
*/
