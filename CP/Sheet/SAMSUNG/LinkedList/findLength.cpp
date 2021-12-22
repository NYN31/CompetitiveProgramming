int length(struct node *root)
{
    int count = 0;
    struct node* temp;
    temp = root;
    while(temp!=NULL){
        count++;
        temp = temp->link;
    }
    return count;
}
