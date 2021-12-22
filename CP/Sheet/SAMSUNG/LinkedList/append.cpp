void append(struct node* root, int num)
{
    struct node* temp;
    if(root == NULL) printf("This function can not be used to add a node to Empty list...........!\n\n");
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = NULL;      /// Now node is ready
    if(root == NULL)
        root = temp;
    else{
        struct node* p;
        p = root;
        while(p->link != NULL)
            p = p->link;
        p->link = temp;
    }
}
