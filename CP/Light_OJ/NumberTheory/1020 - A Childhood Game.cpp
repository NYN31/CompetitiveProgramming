#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long


int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        ll n;
        string s;
        cin>>n>>s;
        if(s[0]=='A') {
            if((n-1)%3==0) printf("Case %d: Bob\n",++no);
            else printf("Case %d: Alice\n",++no);
        }
        else{
            if(n%3 == 0) printf("Case %d: Alice\n",++no);
            else printf("Case %d: Bob\n",++no);
        }
    }
    return 0;
}
