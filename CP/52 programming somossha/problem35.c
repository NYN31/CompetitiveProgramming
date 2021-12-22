#include<stdio.h>
#include<math.h>

int main()
{
    int T, X, Xc, Y, Yc, r;
    double d;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &r);
        scanf("%d %d", &Xc, &Yc);

        scanf("%d %d", &X, &Y);
        d = sqrt((Xc - X)*(Xc - X) + (Yc - Y)*(Yc - Y));
        if(d > r)
            printf("The point is not inside the circle\n");
        else
            printf("The point is inside the cicle\n");
    }

    return 0;
}

