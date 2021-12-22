#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define sz 2000005
#define m INT_MAX

int main(){
    BeatMeScanf;
    priority_queue<ll,vector<ll>,greater<ll>>q;
    map<ll,int>v;
    map<ll,int>::iterator it;
    vector<ll>arr;
    q.push(1);

    while(v.size()<1505){
        ll u=q.top();
        q.pop();
        if(v.count(u)) continue;
        if(u*2<m) q.push(u*2);
        if(u*3<m) q.push(u*3);
        if(u*5<m) q.push(u*5);
        v[u]=1;
    }
    for(it=v.begin();it!=v.end();it++)
        arr.push_back(it->first);
    cout<<"The 1500'th ugly number is "<<arr[1499]<<"."<<endl;

    return 0;
}
///The 1500'th ugly number is <number>.
