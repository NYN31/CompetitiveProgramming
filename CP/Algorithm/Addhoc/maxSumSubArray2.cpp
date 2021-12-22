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
        int idxMax,idxMin,mx=INT_MIN,mn=INT_MAX;
        vector<int>v(n),sum(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        sum[0]=0;
        for(int i=1;i<=v.size();i++){
            sum[i]=sum[i-1]+v[i];
            if(mx<sum[i]){
                idxMax=i;
                mx=sum[i];
            }
        }
        for(int i=1;i<=sum.size();i++) cout<<sum[i]<<" ";cout<<endl;
        cout<<"MAX index: "<<idxMax<<endl;
        for(int i=0;i<idxMax;i++){
            if(mn>sum[i]){
                idxMin=i;
                mn=sum[i];
            }
        }
        cout<<"MIN index: "<<idxMin<<endl;
        cout<<"Maximum sum: "<<sum[idxMax]-sum[idxMin]<<endl;
    }
    return 0;

}

/*
16
4 -3 -2 2 3 1 -2 -3 4 2 -6 -3 -1 3 1 2
*/
