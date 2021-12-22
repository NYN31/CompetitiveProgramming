#include<stdio.h>
#include<math.h>

int main()
{
    int T, a, b, c;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &a, &b, &c);
        double s, area;
        s = (a+b+c)*1.0/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        if(a+b>c && b+c>a && c+a>b){
            printf("Area = %0.3lf\n", area);
        }
    }
    return 0;
}
