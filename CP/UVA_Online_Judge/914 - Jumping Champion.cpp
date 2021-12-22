#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void isprime(ll n, ll m)
{
    bool prime[m+1];

    for(int i = n; i <= m; i++) prime[i] = true;
  prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(m); i++)
    {
        for(int j = 2*i; j <= m; j+=i)
        {
            prime[j] = false;
        }
    }
     vector<ll>v;
    for(int i = n ;i <= m; i++)
    {
        if(prime[i] == true) v.push_back(i);
    }
//  cout << v.size() << endl;
    if(v.size()>1){
        vector<ll>s;
        for(int i = 1; i < v.size(); i++)
        {
            s.push_back(v[i] - v[i-1]);
        }
        // cout << s[0] << endl;
        if(s.size()==1)   cout << "The jumping champion is " << s[0] << endl;
        else{
           vector<ll>::iterator it1;
           it1 = max_element(s.begin(), s.end());
           ll ans = *it1;


           vector<ll>::iterator it2;
           it2 = min_element(s.begin(), s.end());
           ll abs = *it2;

            //cout << abs << endl << ans << endl;
            ll arr[100000] = {0};
            for(ll i = 0; i < s.size(); i++)
            {
                arr[s[i]]++;
            }


            ll ash = arr[abs], loc=abs;

            int flag= 0,count = 0;
            for(ll p = abs+1; p <= ans; p++)
            {

                if(arr[p] > ash){
                    ash = arr[p];
                    // flag = 1;
                    loc = p;
                }
            }
            cout <<  ash << endl;
            for(ll p= abs; p <= ans; p++)
            {
                if(arr[p]==ash){
                    count++;
                }
            }
            //  cout << count;
            if(arr[loc] > 1 && count==1 )
                cout << "The jumping champion is " << loc << endl;
            else{
                cout << "No jumping champion\n";
            }
        }
    }
    else cout << "No jumping champion\n";
}


int main()
{
    int t;
    long long n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if(n == m) cout << "No jumping champion\n";
        else isprime(n,m);
    }
    return 0;
}
