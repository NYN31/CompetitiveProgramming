#include<stdio.h>
 
int main()
{
    int x1, x2, y1, y2, T, i = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int M, x, y;
        scanf("%d", &M);
        printf("Case %d:\n", ++i);
        while(M--){
            scanf("%d %d", &x, &y);
            if(x>x1 && x<x2 && y>y1 && y<y2)      // we can use only the 1st condition using the assignment operator >= and <=
                printf("Yes\n");
            else if(x==x1 || x==x2 || y==y1 || y==y2)   // if(x>=x1 && x<=x2 && y>=y1 && y<=y2);
                printf("No\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
