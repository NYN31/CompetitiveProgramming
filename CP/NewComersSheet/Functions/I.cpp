#include <bits/stdc++.h>
using namespace std ;

int n ;
const int sz = 505 ;

void task1(int x, int y, int arr[sz][sz]) {
        for(int i=1; i<=n; i++) {
                swap(arr[x][i], arr[y][i]) ;
        }
}
void task2(int x, int y, int arr[sz][sz]) {
        for(int i=1; i<=n; i++) {
                swap(arr[i][x], arr[i][y]) ;
        }
}

int main() {
        int x, y ;
        cin >> n >> x >> y ;
        int arr[sz][sz] ;
        for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                        cin >> arr[i][j] ;
                }
        }
        task1(x, y, arr) ;
        task2(x, y, arr) ;
        for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                        cout << arr[i][j] << " " ;
                }
                cout << endl ;
        }
        return 0 ;
}

