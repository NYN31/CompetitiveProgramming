#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 200100

int tree[4*sz];
set<int>st;

void update(int node,int b,int e,int i,int j,int nv){
    if(i>e || j<b) return ;
    if(b>=i && e<=j){
        tree[node]=nv;
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    update(left,b,mid,i,j,nv);
    update(right,mid+1,e,i,j,nv);
}

void query(int node,int b,int e,int carry=tree[1]){
    if(b==e){
        st.insert(carry);
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    query(left,b,mid,max(carry,tree[left]));
    query(right,mid+1,e,max(carry,tree[right]));
}

int main(){
    BeatMeScanf;
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n,poster=0,num=0;
        for(int i=0;i<=4*sz;i++) tree[i]=0;
        scanf("%d",&n);
        vector<pair<int,int>>vec;
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            vec.push_back({a,b});
            mp[a]=1;
            mp[b]=1;
        }
        for(auto it:mp){
            num++;
            mp[it.first]=num;
        }
        for(int i=0;i<vec.size();i++){
            int x,y;
            poster++;
            x=vec[i].first,y=vec[i].second;
            update(1,1,num,mp[x],mp[y],poster);
        }
        query(1,1,num);
        printf("Case %d: %d\n",++no,st.size());
        st.clear();
    }
    return 0;
}
