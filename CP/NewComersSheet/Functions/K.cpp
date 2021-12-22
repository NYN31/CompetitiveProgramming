#include <bits/stdc++.h>
using namespace std ;

void func(int n, int sft, int arr[]) {
        int val = n - sft ;
        for(int i=val+1; i<=n; i++) cout << arr[i] << " " ;
        for(int i=1; i<=val; i++) {
                cout << arr[i] ;
                if(i != val) cout << " " ;
        }
}

int main() {
        int n, x ; cin >> n >> x ;
        int sft = x % n ;
        int arr[n + 5] ;
        for(int i=1; i<=n; i++) cin >> arr[i] ;
        func(n, sft, arr) ;
        return 0 ;
}
