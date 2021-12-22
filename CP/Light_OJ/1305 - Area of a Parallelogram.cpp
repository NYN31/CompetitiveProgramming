#include<stdio.h>
 
int main()
{
    int T, Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, area, i;
    i = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
        double x1, y1;
        x1 = (Ax+Cx)*1.0/2;
        y1 = (Ay+Cy)*1.0/2;
        Dx = (2*x1 - Bx); //Dx = Ax+Cx-Bx;
        Dy = (2*y1 - By); //Dy = Ay+Cy-By;
        area = abs(Ax*By + Bx*Cy + Cx*Ay - Ay*Bx - By*Cx - Cy*Ax);
 
        printf("Case %d: %d %d %d\n", ++i, Dx, Dy, area);
    }
    return 0;
}
 
