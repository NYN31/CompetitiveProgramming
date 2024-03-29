#include<bits/stdc++.h>
using namespace std;
#define ll long long

int const N = 10;
int n;
int coltaken[N+1], d1taken[N+1], d2taken[N+1];
int board[20][20];
bool nqueen(int r) {
    if(r == n) return true;

    for(int c=0;c<n;c++) {
        if(coltaken[c]) continue;
        int d1 = r+c, d2 = r+n-c-1;
        if(d1taken[d1] || d2taken[d2]) continue;

        coltaken[c] = 1;
        d1taken[d1] = 1;
        d2taken[d2] = 1;
        board[r][c] = 1;
        if(nqueen(r+1)) return true;
        coltaken[c] = 0;
        d1taken[d1] = 0;
        d2taken[d2] = 0;
        board[r][c] = 0;
    }
    return false;
}
int main() {
    cin>>n;
    nqueen(0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<< board[i][j]<<" ";
        }
        cout<<endl;
    }
}
