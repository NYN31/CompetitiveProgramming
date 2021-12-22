#include <stdio.h>

int maxf(int n, int arr[]) {
        int mx = -1 ;
        for(int i=0; i<n; i++) {
                if(arr[i] > mx) {
                        mx = arr[i] ;
                }
        }
        return mx ;
}
int minf(int n, int arr[]) {
        int mn = 1e9 ;
        for(int i=0; i<n; i++) {
                if(arr[i] < mn) {
                        mn = arr[i] ;
                }
        }
        return mn ;
}

int main() {
        int n, arr[100005] ;
        scanf("%d", &n) ;
        for(int i=0; i<n; i++) scanf("%d", &arr[i]) ;
        int maxValue = maxf(n, arr) ;
        int minValue = minf(n, arr) ;
        printf("%d %d", minValue, maxValue) ;
        return 0 ;
}

