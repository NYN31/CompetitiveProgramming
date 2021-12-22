#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

int main(){
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        --m;
        int arr[n+5];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<"Case "<<++no<<": ";
        int lo=1,hi=1e9,mid,sum,part,ans,flag;
        while(lo<hi){
            mid=(lo+hi)/2;
            sum=0,part=0,flag=0;
            for(int i=0;i<n;i++){
                if(arr[i]>mid){lo=mid+1;flag=1;break;}
                if(sum+arr[i]<=mid){
                    sum+=arr[i];
                }
                else{
                    part++;
                    sum=arr[i];
                }
            }
            if(flag==1) continue;
            if(part<=m) hi=mid;
            else if(part>m) lo=mid+1;
        }
        cout<<hi<<endl;
    }
    return 0;
}
