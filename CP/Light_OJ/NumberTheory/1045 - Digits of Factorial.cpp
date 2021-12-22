#include<bits/stdc++.h>
using namespace std;
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
    solve();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n,b;
        cin>>n>>b;
        int ans=(prec[n])/log10(b);
        printf("Case %d: %d\n",++no,ans+1);
    }
    return 0;
}
