#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s;
    ll T;
    cin >> T;
    while(T--)
    {
        ll N, num, N2, line, sum = 0;
        char ch;
        double ans;
        map <char, ll> mp;
        vector <char> v;
        map <char, ll>::iterator it;
        cin >> N;
        N2 = N;
        
        while(N--)
        {
            cin >> ch >> num;
            mp[ch] = num;
            v.push_back(ch);
        }
        
        cin >> line;
        cin.ignore();
        while(line--)
        {
            getline(cin, s);
            for(ll i = 0; i<s.size(); i++)
            {
                for(ll j = 0; j<v.size(); j++){
                    if(s[i] == v[j]){
                        sum += mp[v[j]];
                    }
                }
            }
        }
        ans = (sum*1.0)/100;
        printf("%0.2lf$\n", ans);
    }
    return 0;
}
