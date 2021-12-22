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
    int n;
    cin>>n;
    vector<int>v;
 
    if(n==3 || n==2) {
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    for(int i=2;i<=n;i+=2) v.pb(i);
    for(int i=1;i<=n;i+=2) v.pb(i);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
