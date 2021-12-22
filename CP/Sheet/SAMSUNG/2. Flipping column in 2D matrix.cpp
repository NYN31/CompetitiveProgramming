/***
Question:  A binary matrix of n X m was given,
you have to toggle any column k number of times so that
you can get the maximum number of rows having all 1.

=> https://stackoverflow.com/questions/7116438/algorithms-question-flipping-columns

***/

/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000005
#define sz 20

int n, m, k;
int mat[sz+1][sz+1];
int Hash[MAX+5];


void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j] ;
        }
    }


    int maxRow = 0;
    for(int i = 0; i < n; i++) {
        int key = 0 ;
        int countZero = 0 ;

        for(int j = 0; j < m; j++) {
            key += mat[i][j] * (1 << j);
            if(mat[i][j] == 0) countZero += 1;
        }
        int rem = k - countZero ;
        if(rem % 2 == 0 && rem >= 0) {
            Hash[key] += 1;
            if(Hash[key] > maxRow) {
                maxRow = Hash[key];
            }
        }
    }

    cout << maxRow << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    int test = 1, no = 0;
    //cin >> test ;
    while(test--) {
        solve();
    }
    return 0;
}

