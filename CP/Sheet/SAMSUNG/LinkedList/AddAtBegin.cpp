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
