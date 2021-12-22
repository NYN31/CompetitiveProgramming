#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

int main(){
    BeatMeScanf;
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d", &n,&q);
        int arr[n+5];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);;
        printf("Case %d:\n",++no);
        while(q--){
            int a,b,x,y;
            scanf("%d %d",&a,&b);

            int lo=0,hi=n-1,mid,flag=0;
            while(lo<=hi){
                mid=(lo+hi)/2;

                if(arr[mid]==a){
                    x=mid;
                    flag=1;
                    break;
                }
                else if(arr[mid]<a) lo=mid+1;
                else hi=mid-1;
            }
            if(flag==0) x=lo;


            lo=0,hi=n-1,mid,flag=0;
            while(lo<=hi){
                mid=(lo+hi)/2;

                if(arr[mid]==b){
                    y=mid;
                    flag=1;
                    break;
                }
                else if(arr[mid]<b) lo=mid+1;
                else hi=mid-1;
            }
            if(flag==0) y=hi;
            int ans=y-x+1;
            printf("%d\n",ans);
        }
    }
    return 0;
}


/*

#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define mod 10000007

int main(){
    BeatMeScanf;
    int t,no=0;
    scanf("%d", &t);
    while(t--){
        int n,q;
        scanf("%d %d",&n, &q);
        vector<int>v;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d", &a);
            v.push_back(a);
        }
        printf("Case %d:\n",++no);
        while(q--){
            int a,b;
            scanf("%d %d",&a, &b);
            int x=upper_bound(v.begin(),v.end(),b)-v.begin();
            int y=lower_bound(v.begin(),v.end(),a)-v.begin();
            printf("%d\n",x-y);
        }
    }
    return 0;
}
*/
