#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned ll
#define CaseNum cout<<"Case "<<++no<<": "
#define nl "\n"
#define PI 3.14159265358979323846
#define sz 1000005
#define mod 1000000007
#define toint(a) atoll(a.c_str())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
ll power(ll a,ll b){return b==0?:a*power(a,b-1);}
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*(b/gcd(a,b));}
 
 
int main(){
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        ll n,cntOne=0,idx=-1,cnt1=0,n2;
        ll ans=0;
        bool flag=false;
        vector<int>binary;
        cin>>n;
        n2=n;
        cout<<"Case "<<++no<<": ";
        for(int i=0;i<=30;i++){
            ll x=1LL<<i;
            if(n==x){
                ans=2*x;
                cout<<ans<<nl;
                flag=true;
                break;
            }
        }
        if(flag) {binary.clear();continue;}
        while(n){
            binary.push_back(n%2);
            if(n%2==1) cntOne++;
            n/=2;
        }
        n=n2;
        reverse(binary.begin(),binary.end());
 
        for(int i=0;i<binary.size()-1;i++){
            if(binary[i]==0 && binary[i+1]==1){
                flag=true;
                idx=i;
            }
        }
        if(idx==-1){
            binary.push_back(0);
            binary[0]=1;
            cntOne--;
            for(int i=1;i<binary.size();i++) binary[i]=0;
            for(int i=binary.size()-1;i>0;i--){
                if(cntOne==0) break;
                binary[i]=1;
                cntOne--;
            }
            int p=binary.size()-1;
            for(int i=0;i<binary.size();i++) {
                if(binary[i]!=0)
                    ans+=(1LL<<p);
                p--;
            }
            cout<<ans<<nl;
        }
        else{
            for(int i=idx;i<binary.size();i++) if(binary[i]==1) cnt1++;
            binary[idx]=1;
            cnt1--;
            for(int i=binary.size()-1;i>idx;i--){
               if(cnt1>0){
                    binary[i]=1;
                    cnt1--;
               }
               else binary[i]=0;
            }
            int p=binary.size()-1;
            for(int i=0;i<binary.size();i++) {
                if(binary[i]==1)
                    ans+=(1LL<<p);
                p--;
            }
            cout<<ans<<nl;
        }
        binary.clear();
    }
    return 0;
}
