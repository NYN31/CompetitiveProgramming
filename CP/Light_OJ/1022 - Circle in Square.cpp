#include<stdio.h>
#define PI 2*acos(0.0)
 
int main()
{
    int T, i;
    double r;
    scanf("%d", &T);
 
    for(i = 1; i<=T; i++)
    {
        scanf("%lf", &r);
        printf("", i);
        double circle_area, shaded_area;
        circle_area = PI*r*r;
        shaded_area = ((2*r)*(2*r)) - circle_area;
        printf("Case %d: %0.2lf\n", i, shaded_area);
 
    }
    return 0;
}
