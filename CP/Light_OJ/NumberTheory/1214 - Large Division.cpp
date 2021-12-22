#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000100

int main(){
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        string s;
        ll m,rem=0,ans=0;
        cin>>s>>m;
        if(m<0) m*(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='-') continue;
            ans=(rem*10+(s[i]-'0'));
            rem=ans%m;
        }
        if(rem==0) printf("Case %d: divisible\n", ++no);
        else printf("Case %d: not divisible\n", ++no);
    }
    return 0;
}
