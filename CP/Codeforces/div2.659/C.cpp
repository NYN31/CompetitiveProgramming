#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main() {
    int t; cin>>t;
    while(t--) {
        int n;  cin>>n;
        string a, b; cin>>a>>b;
        bool flag = false;
        for(int i=0;i<a.size();i++) {
            if(a[i] > b[i]) {
                flag = true;
                break;
            }
        }
        if(flag) cout<<-1<<endl;
        else{
            int ans = 0;
            for(int i=0;i<26;i++) {
                char ch = (char)(i+'a'), mn = 'z';
                vector<int>pos;
                for(int j=0;j<a.size();j++) {
                    if(a[j] == ch && b[j] > a[j]) {
                        mn = min(mn, b[j]);
                        pos.pb(j);
                    }
                }
                if(mn == 'z') continue;
                ans++;
                for(auto j : pos) a[j] = mn;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
