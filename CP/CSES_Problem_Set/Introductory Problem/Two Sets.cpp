#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define pb push_back
 
int const N = 505;
int const M = 62650;
int const mod = 1e9+7;
 
int main(){
    int n;
    cin>>n;
    vector<int>odd,even;
    ll odds=0, evens=0;
    for(int i=1;i<=n;i++) {
        if(i & 1) odd.pb(i), odds += i;
        else even.pb(i), evens += i;
    }
    int sub = abs(odds-evens);
    if(sub & 1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        int half = sub/2;
        if(!(n & 1)) {
            for(int i=0;i<half;i++) {
                swap(odd[i],even[i]);
            }
        }
        else{
            int i=odd.size()-1,j=even.size()-1;
            while(half--){
                swap(odd[i],even[j]);
                --i,--j;
            }
        }
        cout<<odd.size()<<endl;
        for(int i=0;i<odd.size();i++)
            cout<<odd[i]<<" ";
        cout<<endl;
        cout<<even.size()<<endl;
        for(int i=0;i<even.size();i++)
            cout<<even[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}
