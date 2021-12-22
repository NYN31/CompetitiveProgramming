#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000
ll n,b;

ll zero()
{
    int ans = INF;
    for(int i=2;i*i<=b;i++){
        if(b%i==0){
            int cnt=0;
            while(b%i==0){
                b=b/i;
                cnt++;
            }
            int tmp=1,sum=0;
            while(tmp<=n){
                tmp*=i;
                sum+=(n/tmp);
            }
            ans=min(ans,sum/cnt);
        }
    }
    if(b!=1){
        int tmp=1,sum=0;
        while(tmp<=n){
            tmp*=b;
            sum+=(n/tmp);
        }
        ans=min(ans,sum);
    }
    return ans;
}

ll digit() {
    double sum = 0, logb = log(b);
    for(int i = 1; i <= n; ++i)
        sum += log(i) / logb;
    return (ll)floor(sum) + 1;
}

int main()
{
    while(cin>>n>>b){
        printf("%d %lld\n", zero(),digit());
    }
    return 0;
}

