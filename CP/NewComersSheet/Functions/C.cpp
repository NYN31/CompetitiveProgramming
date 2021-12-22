#include <bits/stdc++.h>
using namespace std ;

int isOdd(int n) {
        return (n % 2 == 1) ;
}

int isPalindrome(int n) {
        int arr[40] , sz = 0;
        while(n != 0) {
                arr[sz] = n % 2;
                n = n / 2 ;
                sz += 1 ;
        }
        for(int i=0; i<sz/2-1; i++) {
                if(arr[i] != arr[sz - i - 1]) {
                        return 0 ;
                }
        }
        return 1 ;
}

int main() {
        int n ; cin >> n ;
        int odd = isOdd(n) ;
        int palindrome = isPalindrome(n) ;
        if(odd == 1 && palindrome == 1) {
                printf("YES") ;
        }else {
                printf("NO") ;
        }
        return 0 ;
}
