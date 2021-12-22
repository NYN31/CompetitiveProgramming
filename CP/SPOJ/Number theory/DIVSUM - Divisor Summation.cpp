#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int const N = 10e6+5;
int div_sum[N+5];
void precal() {
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j+=i){
            div_sum[j] += i;
        }
    }
}
int main() {
    precal();
    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        cout<<div_sum[n]-n<<endl;
    }
    return 0;
}
