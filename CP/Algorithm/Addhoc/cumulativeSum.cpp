#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define ll long long
#define sz 500005
#define mod 1000000007
#define toint(a) atoll(a.c_str())
string tostr(ll n) {stringstream rr;rr<<n;return rr.str();}
ll power(ll a,ll b){return b==0?:a*power(a,b-1);}
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}

int fx[]= {0,-1, 0,1};
int fy[]= {1, 0,-1,0};


int main()
{
    BeatMeScanf;
    int n;
    while(cin>>n){
        vector<int>v(n),sum(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        sum[0]=0;
        for(int i=1;i<=v.size();i++){
            sum[i]=sum[i-1]+v[i];
        }
        //for(int i=0;i<sum.size();i++) cout<<sum[i]<<" ";
        //cout<<endl;
        int t;
        cin>>t;
        while(t--){
            int a,b;
            cin>>a>>b;
            cout<<sum[b]-sum[a];
        }
    }
    return 0;

}
