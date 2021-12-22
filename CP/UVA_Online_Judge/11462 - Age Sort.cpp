#include<bits/stdc++.h>
using namespace std;
#define m 2000005
int arr[m];

void merge(int lo, int mid, int hi)
{
    int i,j,k;
    int n1 = mid-lo+1, n2=hi-mid;
    int L[n1], R[n2];

    for(i=0;i<n1;i++) L[i]=arr[lo+i];
    for(j=0;j<n2;j++) R[j]=arr[mid+1+j];

    i = j = 0; k = lo;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++; k++;
        }
        else
        {
            arr[k] = R[j];
            j++; k++;
        }
    }
    while(i<n1)
    {
        arr[k] = L[i];
        k++; i++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        k++; j++;
    }
}
void merge_sort(int lo, int hi)
{
    int mid;
    if(lo<hi)
    {
        mid = lo+(hi-lo)/2;
        merge_sort(lo, mid);
        merge_sort(mid+1, hi);
        merge(lo, mid, hi);
    }
}
void print(int n)
{
    for(int i = 0; i<n;  i++)
    {
        cout << arr[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    while(cin >> n && n!=0)
    {
        for(int i=0; i<n; i++) cin >> arr[i];
        merge_sort(0, n-1);
        print(n);
    }
    return 0;
}
