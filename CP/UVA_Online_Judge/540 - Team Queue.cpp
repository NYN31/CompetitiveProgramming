#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main()
{
    BeatMeScanf;
    int t,no=0;
    map<int,int>mp;
    queue<int>qq[1100];

    while(cin>>t && t!=0){
        mp.clear();
        for(int tm=1;tm<=t;tm++){
            while(!(qq[tm].empty())){
                qq[tm].pop();
            }
            int n;
            cin>>n;
            for(int i=1;i<=n;i++){
                int a;
                cin>>a;
                mp[a]=tm;
            }
        }
        queue<int>qpos;
        string s;
        cout<<"Scenario #"<<++no<<endl;
        while(cin>>s && s[0]!='S'){
            if(s[0]=='E'){
                int a; cin>>a;
                int tm = mp[a];
                if(qq[tm].empty()){
                    qpos.push(tm);
                }
                qq[tm].push(a);
            }
            else{
                int u=qpos.front();
                int v=qq[u].front();
                qq[u].pop();
                cout<<v<<endl;
                if(qq[u].empty()) qpos.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}

