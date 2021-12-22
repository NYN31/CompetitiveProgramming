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
