#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define Case(n) printf("Case %d: ",++no)

ll cheak_zeroes(ll mid){
    ll p=5,num=mid,i=1,cnt=0;
    while(1){
        if(num/p==0) break;
        cnt+=num/p;
        p*=5;
    }
    return cnt;
}

int main(){
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        ll n,ans=-1;
        cin>>n;
        cout<<"Case "<<++no<<": ";
        ll lo=0,hi=1e15,mid;
        while(lo<=hi){
            mid=(lo+hi)/2;

            ll x=cheak_zeroes(mid);
            if(x==n){
                ans=mid;
                break;
            }
            else if(x>n) hi=mid-1;
            else lo=mid+1;
        }
        if(ans==-1) cout<<"impossible"<<endl;
        else {
            ll x=ans,y;
            while(1){
                y=cheak_zeroes(x);
                if(y<n) break;
                ans=x;
                x--;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
