//Linked List(one way)

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int len;

int length(struct node *root)
{
    int cnt = 0;
    struct node* temp;
    temp = root;
    while(temp!=NULL){
        cnt++;
        temp = temp->link;
    }
    return cnt;
}


void append(struct node **root, int num)
{
    struct node* temp;
    //if(root == NULL) printf("This function can not be used to add a node to Empty list...........!\n\n");
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = NULL;      /// Now node is ready
    if(*root == NULL) *root = temp;
    else{
        struct node* p;
        p = *root;
        while(p->link != NULL)
            p = p->link;
        p->link = temp;
    }
}

struct node* addatbegin(struct node* root, int num)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = NULL;      /// Now node is ready
    if(root == NULL)
        root = temp;
    else{
        temp->link = root;   /// right connection
        root = temp;  /// left connection
    }
    return root;
}

void addInMid(struct node* root)
{
    struct node* temp, *p;
    int loc, i = 1;
    printf("Enter the location of a node: ");
    scanf("%d", &loc);   /// After which location we are located the value
    len = length(root);
    if(loc>len)
        printf("Invalid location....!!!\n\n");
    else{
        p = root;
        while(i<loc){
            p = p->link;
            i++;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter the Number:  ");
        scanf("%d", &temp->data);
        temp->link = NULL;
        temp->link = p->link; ///  Right side connection 1st
        p->link = temp;  ///  Left side connection second
    }
}

void del(struct node* root)
{
    struct node* temp;
    int loc, i = 1;
    printf("Enter the location: ");
    scanf("%d", &loc);
    if(loc>length(root))
        printf("Invalid location...!!!\n\n");
    else if(loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else{
        struct node* p = root, *q;
        while(i<loc-1){
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}


void display(struct node* root)
{
    struct node* temp;
    temp = root;
    if(temp == NULL) printf("List is Empty...!!!\n\n");
    else{
        while(temp!=NULL){
            printf("%d  ", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}

int main()
{
    struct node* root = NULL;
    int ch, num;
    while(1){
        printf("1.Append: \n");
        printf("2.Add at Begin: \n");
        printf("3.length: \n");
        printf("4.Display: \n");
        printf("5.Insert in mid: \n");
        printf("6.Delete node: \n\n");

        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:     printf("Enter the data: ");
                        scanf("%d", &num);
                        append(&root, num);
                        break;
            case 2:     printf("Enter the number at the begin: ");
                        scanf("%d", &num);
                        root = addatbegin(root, num);
                        break;
            case 3:     len = length(root);
                        printf("Length is: %d\n\n", len);
                        break;
            case 4:     display(root);
                        break;
            case 5:     addInMid(root);
                        break;
            case 6:     del(root);
                        break;
            default:    printf("Invalid input....!!! \n\n");
        }
    }
    return 0;
}
