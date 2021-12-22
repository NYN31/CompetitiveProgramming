#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
 
int main()
{
    BeatMeScanf;
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        if((b+1)/2 > a || (a==2 && b==3) || (a==0&&b!=0)) {
            cout<<"NO"<<endl;
            continue;
        }
        a = a%3, b = b%3;
        if(a>b) swap(a,b);
        if(a==1&&b==1 || a==2&&b==2 || a==0&&b!=0)
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
