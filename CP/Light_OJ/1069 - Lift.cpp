#include<stdio.h>
 
int main()
{
    int T, my_pos, lift_pos, i = 0, total;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &my_pos, &lift_pos);
        int opn_cls = 9, ent_ext = 10;
        total = 0;
        if(my_pos > lift_pos){
            total = (my_pos - lift_pos)*4;
            lift_pos = my_pos;
        }
 
        total += opn_cls + ent_ext + (lift_pos*4);
        printf("Case %d: %d\n", ++i, total);
    }
 
    return 0;
}
