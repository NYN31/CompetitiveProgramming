#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define sz 1000100
 
double prec[sz];
void solve(){
    prec[0]=0;
    prec[1]=0;
    for(int i=2;i<=sz;i++){
        prec[i]=prec[i-1]+log10(i);
    }
}
 
int main(){
    BeatMeScanf;
    solve();
    int t,no=0;
    cin>>t;
    while(t--){
        int n,b;
        cin>>n>>b;
        cout<<"Case "<<++no<<": ";
        int ans=(prec[n])/log10(b);
        cout<<ans+1<<endl;
    }
    return 0;
}
