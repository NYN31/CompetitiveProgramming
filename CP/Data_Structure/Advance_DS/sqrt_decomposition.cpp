#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 100100

int n,q,k;
int arr[sz],seg[1050];

int build(){
    int block=sqrt(n); /// block size
    int cur_seg=-1;

    for(int i=0;i<n;i++){
        /// i%block means previous segment has updated, now new segment has to be calculated
        /// cur_seg++ means new segment
        if(i%block==0) cur_seg++;
        seg[cur_seg]+=arr[i];
    }
    return block;
}

int query(int lo,int hi){
    int sum=0;
    /// left most size that means some element of this block has to be calculated
    while(lo<hi && lo%k != 0){
        sum+=arr[lo];
        ++lo;
    }
    /// whole block has to be calculated
    while(lo+k<=hi){
        sum+=seg[lo/k];
        lo+=k;
    }
    /// right most size that means some element of this block has to be calculated
    while(lo<=hi){
        sum+=arr[lo];
        ++lo;
    }
    return sum;
}

/***
updated function:

    void update(int input[], int segment_size, int i, int val) {
        int segment_no = i / segment_size;

        segment[segment_no] -= input[i];
        segment[segment_no] += val;
        input[i] = val;
    }

***/

int main()
{
    BeatMeScanf;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    k=build(); /// Pre-precess & k means block size
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int ans=query(a,b);
        cout<<ans<<endl;
    }
    return 0;
}

