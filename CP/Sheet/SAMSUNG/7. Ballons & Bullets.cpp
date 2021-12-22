/***
    Question:
    Solution: Using Dividing and Conquer Technique
***/
#include <iostream>
using namespace std;

// recursive function to generate scores
int getmaxscore(int arr[], int l, int r, int n)
{
    int mscore = 0;
    for (int i = l + 1; i < r; i++) {
        int cs = getmaxscore(arr, l, i, n) + getmaxscore(arr, i, r, n);
        if (l == 0 && r == n)
            cs = cs + arr[i];
        else
            cs = cs + (arr[l] * arr[r]);

        if (cs > mscore)
            mscore = cs;
    }
    return mscore;
}

int main() // driver function
{
    int n ; cin >> n ;
    int arr[n + 5];
    for(int i=1; i<=n; i++) cin >> arr[i];
    arr[0] = arr[n + 1] = 1;
    cout << getmaxscore(arr, 0, n + 1, n + 1) << "\n";

    return 0;
}

