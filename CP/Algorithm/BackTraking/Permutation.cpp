/// Array permutation

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

int const N = 100;

int n;
int arr[N+5];
bool taken[N+5];
vector<int>ans;

void permutation(int in) {
    if(in == n) {
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    for(int j=0;j<n;j++) {
        if(taken[j]) continue;
        taken[j] = true;
        ans.pb(arr[j]);
        permutation(in+1);
        taken[j]=false;
        ans.pop_back();
    }
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    permutation(0);
    return 0;
}



/// Permutation from 1 to n

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

int const N = 100;

int n;
int arr[N+5];
bool taken[N+5];
vector<int>ans;

void permutation(int in) {
    if(in > n) {
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    for(int j=1;j<=n;j++) {
        if(taken[j]) continue;
        taken[j] = true;
        ans.pb(j);
        permutation(in+1);
        taken[j]=false;
        ans.pop_back();
    }
}
int main() {
    cin>>n;
    cout<<"All permutation are: "<<endl;
    permutation(1);
    return 0;
}

