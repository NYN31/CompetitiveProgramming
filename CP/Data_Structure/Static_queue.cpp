#include<stdio.h>
#define max 5
int queue[max];
int p = 0, q = 0;

void display()
{
    int i;
    if(q == p)
        printf("Queue is Empty\n");
    else{
        for(i = 0; i<p; i++){
            printf("%d  ", queue[i]);
        }
        printf("\n\n");
    }
}


void insert()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    if(p == max){
        printf("Queue is Full\n");
    }
    else{
        queue[p] = num;
        p++;
    }
    display();
}
void del()
{
    int i;
    if(p == q)
        printf("Queue is Empty\n");
    else{
        printf("Deleted item: %d\n", queue[q]);
        for(i = 0; i< p-1; i++)
            queue[i] = queue[i+1];
        p--;
    }
    display();
}

int main()
{
    int c;
    while(1){
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.display\n\n");

        printf("Enter the choice: ");
        scanf("%d", &c);
        if(c == 1)
            insert();
        else if(c == 2)
            del();
        else if(c == 3)
            display();
    }


    return 0;
}
