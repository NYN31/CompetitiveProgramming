#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll GetAns(ll n)
{
    ll digit = 1,current = 1;
    while(current%n != 0)
    {
        current = (current*10+1)%n;
        digit++;
    }
    return digit;
}
int main()
{
    ll n;
    while(cin >> n)
    {
        cout << GetAns(n) << endl;
    }
    return 0;
}
