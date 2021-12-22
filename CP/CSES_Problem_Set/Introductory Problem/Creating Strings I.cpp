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
 
const int mod = 1e9+7;
 
int main()
{
    BeatMeScanf;
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    set<string>st;
    do{
        st.insert(str);
    }while(next_permutation(str.begin(),str.end()));
 
    cout<<st.size()<<endl;
    for(auto x : st) cout<<x<<endl;
    return 0;
}
