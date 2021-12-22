#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long



int main(){
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        double x,y,c;
        cin>>x>>y>>c;

        double lo=1,hi=min(x,y),mid,a,b,ans,q=100;
        while(--q){
            mid=(lo+hi)/2;
            a=sqrt(x*x-mid*mid);
            b=sqrt(y*y-mid*mid);
            ans=(a*b)/(a+b);
            if(ans<=c) hi=mid;
            else lo=mid;
        }
        cout<<"Case "<<++no<<": ";
        cout<<fixed<<setprecision(10)<<hi<<endl;
    }
    return 0;
}
