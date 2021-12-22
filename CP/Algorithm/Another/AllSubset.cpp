#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios::sync_with_stdio(0)
#define ll long long
#define nl "\n"
#define PI 3.14159265358979323846
#define sz 1000005
#define mod 1000000007
#define toint(a) atoll(a.c_str())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
ll power(ll a,ll b){return b==0?:a*power(a,b-1);}
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*(b/gcd(a,b));}


void combinationUtil(int arr[],int n,int r,int index,int data[],int i);
void printCombination(int arr[],int n,int r){
    int data[r];
    combinationUtil(arr,n,r,0,data,0);
}

void combinationUtil(int arr[],int n,int r,int index,int data[],int i)
{
    if (index==r){
        for (int j=0;j<r;j++)
            printf("%d ",data[j]);
        printf("\n");
        return;
    }
    if (i>=n) return;

    data[index]=arr[i];
    combinationUtil(arr,n,r,index+1,data,i+1);
    combinationUtil(arr,n,r,index,data,i+1);
}

int main()
{
    int n,r,arr[50];
    cin>>n>>r;
    for(int i=0;i<n;i++) cin>>arr[i];
    printCombination(arr,n,r);
    return 0;
}
