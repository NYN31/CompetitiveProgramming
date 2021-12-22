// Circular Queue

#include<stdio.h>
#define size 5
int Cqueue[size];
int front = -1, rear = -1;


void insert(int ele)
{
    if((front == rear+1) || (rear == size-1))
        printf("QUEUE is Full");
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if(rear == size-1){
        rear = 0;
    }
    else{
        rear++;
    }
    Cqueue[rear] = ele;
}

void delet()
{
    if(front == -1 && rear == -1)
        printf("Cqueue is Empty..!!\n");
    ele = Cqueue[front];
    else if(front == rear){
        front = rear = -1;
    }
    else if(front == size-1){
        front = 0;
    }
    else{
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",Cqueue[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", Cqueue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", Cqueue[i]);
    }
}


int main()
{
    int ch, item;
    while(1){
        printf("1.Push element. \n");
        printf("2.Pop element. \n");
        printf("3.Display element. \n");
        printf("4.Exist.\n");

        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter the element: ");
                    scanf("%d", &item);
                    insert(item);
                    break;
            case 2: delet();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exist ...\n\n");
                    return (0);

            default: printf("Invalid number...!\n");
        }
    }
}
