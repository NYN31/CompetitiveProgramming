#include<stdio.h>
#define CAP 5


int stack[CAP];
int top = -1;
int isFull();
void push(int element);
int pop();
int isEmpty();
void peek() ;
void display();


int main()
{
    int ch, item;
    while(1){
        printf("1.Push element. \n");
        printf("2.Pop element. \n");
        printf("3.Display element. \n");
        printf("4.Peel element. \n");
        printf("5.Exist.\n");

        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter the element: ");
                    scanf("%d", &item);
                    push(item);
                    break;
            case 2: item = pop();
                    if(item == 0)
                        printf("Stack is Empty\n");
                    else{
                        printf("Popped item: %d\n", item);
                    }
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("Exist ...\n\n");
                    return (0);

            default: printf("Invalid number...!\n");
        }
    }
}
void push(int element)    //// PUSH function
{
    if(isFull()){
        printf("Stack is Full\n\n");
    }
    else{
        top++;
        stack[top] = element;
        printf("%d\n", top);
        printf("%d inserted \n\n", element);
    }
}
int isFull()
{
    if(top == CAP-1) return 1;

    else return 0;
}
int pop()     //// POP function
{
    if(isEmpty())
        return 0;
    else{
        return stack[top--];
    }
}
int isEmpty()
{
    if(top == -1)
        return 1;
    else return 0;
}
void peek()    //// PEEK function
{
    if(isEmpty()){
        printf("Stack is Empty\n\n");
    }
    else printf("Top element is: %d\n\n", stack[top]);
}

void display()  /// DISPLAY
{
    if(isEmpty()){
        printf("Stack is Empty\n\n");
    }
    else {
        int i;
        printf("Stack elements are: \n");
        for(i = top; i>=0; i--)
            printf("%d  ", stack[i]);
        printf("\n\n");
    }

}
