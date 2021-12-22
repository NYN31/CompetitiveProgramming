
/***
Question: control - spaceship
For more details: https://www.geeksforgeeks.org/samsung-interview-experience-set-28-campus/

***/

/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'
#define sz 20
#define inf 10000000

int grid[sz + 1][sz + 1];
int enemy[25][2];
int cnt, maxCoins;
int row, col;
bool boom = false;

void destroyEnemy(int start) {
    cnt = 0;
    for(int i=start; i<row && i<start+5; i++) {
        for(int j=0; j<5; j++) {
            if(grid[i][j] == 2) {
                enemy[cnt][0] = i;
                enemy[cnt][1] = j;
                cnt += 1;
                grid[i][j] = 0;
            }
        }
    }
}

void restoreEnemy() {
    for(int i=0; i<cnt; i++) {
        int x = enemy[i][0];
        int y = enemy[i][1];
        grid[x][y] = 2;
    }
}

void go(int r, int c, int coins) {
    if(c < 0 || c >= 5) return ;
    if(r == row) {
        if(coins > maxCoins)
            maxCoins = coins;
        return ;
    }

    if(grid[r][c] == 1) coins += 1 ;
    else if(grid[r][c] == 2) {
        if(boom == true) {
            // end game here
            if(coins > maxCoins)
                maxCoins = coins;
            return ;
        }
        else {
            boom = true;
            destroyEnemy(r);
        }
    }

    go(r + 1, c, coins);
    go(r + 1, c + 1, coins);
    go(r + 1, c - 1, coins);

    if(boom == true) {
        restoreEnemy();
        boom = false;
    }
}

void solve() {
    cin >> row >> col;
    for(int i = row - 1; i >= 0; i--) {
        cin >> grid[i][0];
        cin >> grid[i][1];
        cin >> grid[i][2];
        cin >> grid[i][3];
        cin >> grid[i][4];
    }

    maxCoins = 0;

    go(0, 2, 0);
    go(0, 1, 0);
    go(0, 3, 0);

    cout << maxCoins << endl;
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


/*
8 5
1 1 1 1 1
2 2 2 2 2
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
2 2 2 2 2
2 2 0 2 2
0 1 0 2 2

6 5
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1

*/

