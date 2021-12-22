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
