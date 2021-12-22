#include<stdio.h>

int main()
{
    int T, r1, r2, B, played_ball;
    double current_rr, asking_rr;

        printf("1st innings run: ");
        scanf("%d", &r1);
        printf("\n");

        printf("2st innings run: ");
        scanf("%d", &r2);
        printf("\n");

        printf("ball have: ");
        scanf("%d", &B);
        printf("\n");

        played_ball = 300 - B;
        current_rr = (r2*1.0/played_ball)*6;
        asking_rr =((r1-r2+1)*1.0/B)*6;
        printf("current run rate: %0.2lf\n", current_rr);
        printf("asking run rate: %0.2lf\n\n\n", asking_rr);


    return 0;
}

