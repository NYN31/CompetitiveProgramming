/// Strongly Connected Component


#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<string,vector<string>>g,r;
map<string,vector<string>>::iterator it1;
map<string,bool>vis1,vis2;
map<string,bool>::iterator t1;
vector<string>top,ans;

void init(){
    top.clear();
    vis1.clear();
    vis2.clear();
    ans.clear();
    for(it1=g.begin();it1!=g.end();it1++)
        g[it1->first].clear();
    for(it1=r.begin();it1!=r.end();it1++)
        r[it1->first].clear();
}

void dfs1(string s){
    vis1[s]=true;
    for(int it1=0;it1<g[s].size();it1++){
        string v=g[s][it1];
        if(vis1[v]==false){
            dfs1(v);
        }
    }
    top.push_back(s);
}

void dfs2(string s){
    vis2[s]=true;
    ans.push_back(s);
    for(int it1=0;it1<r[s].size();it1++){
        string v=r[s][it1];
        if(vis2[v]==false){
            dfs2(v);
        }
    }
}

int main()
{
    int n,e,no=0;
    while(cin>>n>>e){
        if(n==0 && e==0) break;
        init();
        string n1,n2;
        for(int i=0;i<e;i++){
            cin>>n1>>n2;
            g[n1].push_back(n2);
            r[n2].push_back(n1);
            vis1[n1]=false;
            vis1[n2]=false;
            vis2[n2]=false;
            vis2[n1]=false;
        }
        cout<<"Calling circles for data set "<<++no<<":\n";
        for(t1=vis1.begin();t1!=vis1.end();t1++){
            string s;
            s=t1->first;
            if(!(vis1[s])){
                dfs1(s);
            }
        }
        for(int i=top.size()-1;i>=0;i--){
            string s=top[i];
            if(!(vis2[s])){
                dfs2(s);
                for(int i=0;i<ans.size();i++){
                    cout<<ans[i];
                    if(i!=ans.size()-1) cout<<", ";
                    else cout<<endl;
                }
            }
            ans.clear();
        }
    }
    return 0;

}
