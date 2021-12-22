#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>

ll power(ll a, ll n)
{
    if(n==0) return 1;
    else return a*power(a,n-1);
}
void solve(ll a)
{
    vector<pair<int,int> >arr;
    vector<ii>::reverse_iterator it;
    int cnt=0;
    while(a%2==0){
        cnt++;
        a=a/2;
    }
    if(cnt>0) arr.push_back(make_pair(2,cnt));
    for(int i=3;i*i<=a;i+=2){
        cnt=0;
        while(a%i==0){
            cnt++;
            a=a/i;
        }
        if(cnt>0) arr.push_back(make_pair(i,cnt));
    }
    if(a>2) arr.push_back(make_pair(a,1));
    int i=1;
    for(it=arr.rbegin();it!=arr.rend();it++){
        cout<<it->first<<" "<<it->second;
        if(i==arr.size()) break;
        i++;
        cout<<" ";
    }
    cout<<endl;
    arr.clear();
}

int main()
{
    string s;
    while(getline(cin,s)&&s!="0")
    {
        int n, e,a=1;
        stringstream ss(s);
        vector<ii> r;
        vector<ii>::iterator it;
        while (ss >> n >> e) {
            r.push_back(make_pair(n, e));
        }
        for(it=r.begin();it!=r.end();it++)
            a*=power(it->first,it->second);
        a=a-1;
        solve(a);
    }
    return 0;
}
