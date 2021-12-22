#include <stdio.h>

void swapping(int &a, int &b) {
        int temp ;
        temp = a ;
        a = b ;
        b = temp ;
        printf("%d %d", a, b) ;
}

int main() {
        int a, b ;
        scanf("%d %d", &a, &b) ;
        swapping(a, b) ;
        return 0 ;
}

