#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

ll const N = 1050;
vector<pair<int,int>>divi;
vector<ll>vec;

bool cmp(const pii &a , const pii &b) {
    if(a.ff == b.ff) return a.ss > b.ss;
    else return a.ff < b.ff;
}

void precal() {
    divi.pb({1,1});
    for(int n=2;n<=1000;n++) {
        int ans = 0;
        for(int i=1;i*i<=n;i++) {
            if(n%i == 0) {
                if(n/i == i) ans++;
                else ans+=2;
            }
        }
        divi.pb({ans, n});
    }
    sort(divi.begin(), divi.end(), cmp);
}

int main() {
    precal();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("Case %d: ",++no);
        cout<<divi[n-1].ss<<endl;
    }
    return 0;
}



#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

ll const N = 1050;
vector<ll>divi[N+5];
vector<ll>vec;

void precal() {
    divi[1].pb(1);
    for(int n=2;n<=1000;n++) {
        int ans = 0;
        for(int i=1;i*i<=n;i++) {
            if(n%i == 0) {
                if(n/i == i) ans++;
                else ans+=2;
            }
        }
        divi[ans].pb(n);
    }
    for(int i=1;i<=32;i++) {
        sort(divi[i].rbegin(), divi[i].rend());
        for(int j=0;j<divi[i].size();j++) {
            vec.pb(divi[i][j]);
        }
    }
}

int main() {
    precal();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("Case %d: ",++no);
        cout<<vec[n-1]<<endl;
    }
    return 0;
}
