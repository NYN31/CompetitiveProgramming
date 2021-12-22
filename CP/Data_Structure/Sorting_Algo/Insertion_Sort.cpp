#include<iostream>
using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        int A[100], j, item;
        for(int i = 1; i<=N; i++)
            cin >> A[i];
        for(int i = 2; i<=N; i++)
        {
            item = A[i];
            j = i-1;
            while(j>=1 && A[j]>item){
                A[j+1] = A[j];
                j = j-1;
            }
            A[j+1] = item;
        }
        for(int i=1; i<=N; i++)
            cout << A[i] << " ";
        cout << endl;
    }
    return 0;
}
