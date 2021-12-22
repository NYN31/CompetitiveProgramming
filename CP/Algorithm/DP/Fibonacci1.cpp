#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fib[100];
void prealoc()
{
    fib[0] = fib[1] = 1;
    for(ll i=2; i<=90; i++)
        fib[i] = fib[i-1]+fib[i-2];
}

int main()
{
    prealoc();
    ll n;
    cin >> n;
    cout << fib[n] << endl;
    return 0;
}


/// recursive 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fib[100];

ll way(ll n)
{
    if(n == 0 || n == 1) return 1;
    else if(fib[n] != -1) return fib[n];
    return fib[n] = way(n-1)+way(n-2);
}

int main()
{
    memset(fib, -1, sizeof(fib));
    ll n;
    cin >> n;
    cout << way(n) << endl;
    return 0;
}
