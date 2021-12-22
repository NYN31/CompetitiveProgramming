#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll N, M;
    while(cin >> N >> M && N != 0 && M != 0)
    {
        set<ll>s;
        ll num1, num2, pos, count = 0;
        while(N--){
            cin >> num1;
            s.insert(num1);
        }
        while(M--){
            cin >> num2;
            if(s.find(num2) != s.end())
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
