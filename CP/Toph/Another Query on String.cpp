#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 100100
#define segment int left=node*2, right=left+1, mid=(b+e)/2
int n,q, tree[4*sz][26];
string str;

void build(int node,int b,int e){
    if(b==e){
        for(int i=0;i<26;i++) tree[node][str[b]-'a']=1;
        return;
    }
    segment;
    build(left,b,mid);
    build(right,mid+1,e);
    for(int i=0;i<26;i++)
        tree[node][i]=tree[left][i] + tree[right][i];
}

void update(int node,int b,int e,int pos,char nc){
    if(pos>e || pos<b) return;
    if(pos==b && pos==e) {
        for(int i=0;i<26;i++) tree[node][i]=0;
        tree[node][nc-'a']=1;
        return ;
    }
    segment;
    update(left,b,mid,pos,nc);
    update(right,mid+1,e,pos,nc);
    for(int i=0;i<26;i++)
        tree[node][i]=tree[left][i] + tree[right][i];
}

vector<int> query(int node,int b,int e,int i,int j){
    if(i>e || j<b) {
        vector<int>v(26);
        for(int i=0;i<26;i++) v[i]=0;
        return v;
    }
    if(b>=i && e<=j){
        vector<int>v(26);
        for(int i=0;i<26;i++) v[i]+=tree[node][i];
        return v;
    }
    segment;
    vector<int>p = query(left,b,mid,i,j);
    vector<int>q = query(right,mid+1,e,i,j);
    vector<int>v(26);
    for(int i=0;i<26;i++) v[i]=p[i]+q[i];
    return v;
}

int main()
{
    BeatMeScanf;
    cin>>n>>q>>str;
    str=' '+str;
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int ch;
        cin>>ch;
        if(ch==1){
            int a;
            char ch;
            cin>>a>>ch;
            update(1,1,n,a,ch);
        }
        else{
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            vector<int>vec=query(1,1,n,a,b);
            cout<<vec[ch-'a']<<endl;
        }
    }
    return 0;
}
