#include<iostream>
#include<algorithm>
using namespace std;
int Partition(int A[], int p, int r);
void quick_sort(int A[], int p, int r)
{
	int q;
	if(p<r)
	{
		q = Partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}
int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p-1;
	for(int j = p; j<=r-1; j++)
	{
		if(A[j]<=x){
			i = i+1;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);
	return i+1;
}
int main()
{
	int n, A[100];
	cin >> n;
	for(int i = 1; i<=n; i++) cin >> A[i];
	quick_sort(A, 1, n);
	for(int i = 1; i<=n; i++) cout << A[i] << " ";
	cout << endl;
}
