#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll T;
    cin >> T;
    while(T--){
        ll hartal[4000] = {0}, total_days, party, party_num[105];
        cin >> total_days >> party;

        for(ll i = 0; i<party; i++)
            cin >> party_num[i];
        for(ll i = 0; i<party; i++){
            for(ll j = 1; j<=total_days; j++){
                if(j%7 == 0){
                    hartal[j]=0;
                }
                else if(j%party_num[i] == 0){
                    if((j+1)%7 == 0) hartal[j] = 0;
                    else hartal[j] = 1;
                }
            }
        }
        ll c = 0;
        for(ll i = 1; i<=total_days; i++){
            if(hartal[i]){
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}
