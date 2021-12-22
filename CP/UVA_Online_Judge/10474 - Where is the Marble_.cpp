#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
ll binpow(ll n, ll p) {if(p==0) return 1LL;if(p%2==0){ll res=binpow(n,p/2);return res*res;}return n*binpow(n,p-1);}
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}

int main(){
    BeatMeScanf;
    int n,q,no=0;
    while(cin>>n>>q && n!=0 && q!=0){
        vector<int>v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());

        cout<<"CASE# "<<++no<<":"<<endl;
        while(q--){
            int x;
            cin>>x;
            int lo=0,hi=n,mid,ans=-1;
            while(lo<hi){
                mid=(lo+hi)/2;
                if(v[mid]==x){
                    hi=mid;
                    ans=hi;
                }
                else if(v[mid]>x) hi=mid;
                else if(v[mid]<x) lo=mid+1;
            }
            if(ans==-1) cout<<x<<" not found"<<endl;
            else cout<<x<<" found at "<<ans+1<<endl;
        }
    }
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
ll binpow(ll n, ll p) {if(p==0) return 1LL;if(p%2==0){ll res=binpow(n,p/2);return res*res;}return n*binpow(n,p-1);}
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}

int main(){
    BeatMeScanf;
    int n,q,no=0;
    while(cin>>n>>q && n!=0 && q!=0){
        vector<int>v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());

        cout<<"CASE# "<<++no<<":"<<endl;
        while(q--){
            int x;
            cin>>x;
            int lo=0,hi=n,mid,ans=-1;
            int ind = lower_bound(v.begin(),v.end(), x) - v.begin();
            if(v[ind]== x) cout<<x<<" found at "<<ind+1<<endl;
            else cout<<x<<" not found"<<endl;
        }
    }
    return 0;
}
*/
