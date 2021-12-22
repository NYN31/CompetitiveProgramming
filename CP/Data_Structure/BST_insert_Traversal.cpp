#include<stdio.h>
#include<stdlib.h>
#define max 10000

typedef struct node Node;
struct node{
    int data;
    Node *left;
    Node *right;
};


Node *create_node(int item)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error! Could not Create A new Node\n");
    }
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}



Node *insert(Node *root, Node *node)
{
    Node *parent_node, *current_node;
    if(root == NULL){
        root = node;
        return root;
    }
    parent_node = NULL;
    current_node = root;

    while(current_node){
        parent_node = current_node;
        if(node->data < current_node->data)
            current_node = current_node->left;
        else current_node = current_node->right;
    }
    if(node->data < parent_node->data)
        parent_node->left = node;
    else
        parent_node->right = node;

    return root;
}



void pre_order(Node* node)
{
    printf("%d ", node->data);

    if(node->left) pre_order(node->left);
    if(node->right) pre_order(node->right);
}
void post_order(Node* node)
{
    if(node->left) post_order(node->left);
    if(node->right) post_order(node->right);

    printf("%d ", node->data);
}
void in_order(Node* node)
{
    if(node->left) in_order(node->left);

    printf("%d ", node->data);

    if(node->right) in_order(node->right);
}


Node* bst_search(Node* root, int item)
{
    Node* node = root;
    while(node){
        if(node->data == item){
            return node;
        }
        if(item < node->data)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

int search(Node* root, int data)
{
    if(root == NULL) return 0;
    else if(root->data == data) return 1;
    else if(data<=root->data) return search(root->left, data);
    else return search(root->right, data);
}


Node *create_bst()
{
    Node *root, *node;
    int array[100];
    int i, n;
    scanf("%d", &n);
    for(i = 0; i<n; i++)
        scanf("%d", &array[i]);
    root = create_node(10);
    for(i = 0; i<n; i++){
        node = create_node(array[i]);
        root = insert(root, node);
        printf("%d\n", root->data);
    }
    return root;
}



int main()
{
    Node *root = create_bst();
    printf("%d\n", root->data);
    int num, num2;
    printf("Enter the search number: ");
    scanf("%d", &num2);
   /* Node* node;    /// search any number from BST
    node = bst_search(root, num2);
    if(node)
        printf("%d is found\n", node->data);
    else
        printf("%d is not found\n");*/

    while(1){
        if(search(root, num2)) printf("Found\n");
        else printf("Not found\n");
        printf("Which traverse I prefer:\n");
        scanf("%d", &num);
        if(num == 1) pre_order(root);
        else if(num == 2) post_order(root);
        else if(num == 3) in_order(root);
        else break;
    }
    printf("\n");
    return 0;
}
