#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define up 2147483648
ll binpow(ll n, ll p) {if(p==0) return 1LL;if(p%2==0){ll res=binpow(n,p/2);return res*res;}return n*binpow(n,p-1);}

vector<ll>po;
void gen(){
    for(int i=0;i<=33;i++){
        for(int j=0;j<=33;j++){
            ll temp=binpow(2,i);
            if(temp>up) break;
            temp=temp*binpow(3,j);
            if(temp>up) break;
            po.push_back(temp);
        }
    }
    sort(po.begin(),po.end());
    po.erase(unique(po.begin(),po.end()),po.end());
   // for(int i=0;i<po.size();i++) cout<<po[i]<<" ";cout<<endl;
}

int main(){
    BeatMeScanf;
    gen();
    int n;
    while(cin>>n && n){
        ll x=upper_bound(po.begin(),po.end(),n)-po.begin();

        if(po[x-1]==n) cout<<n<<endl;
        else cout<<po[x]<<endl;
    }
    return 0;
}
