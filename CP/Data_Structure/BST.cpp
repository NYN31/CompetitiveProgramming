/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;

int sortedArray[105], pt;
int arr[105];

class node {
public:
      int data;
      node* parent;
      node* left;
      node* right;
};

class bst{
public:
      node* root ;
      bst(){root = NULL;}
      node* createNode(int data) ;
      void addLeftChild(node* parent,node* child);
      void addRightChild(node* parent,node* child);
      void insertNode(int data) ;
      void inOrder(node* currentNode) ;
      void preOrder(node* currentNode) ;
      void postOrder(node* currentNode) ;
      bool isFound(int data) ;
};

/**** Create Node ****/
node* bst:: createNode(int data) {
    node* newNode = new node ;
    newNode->data = data ;
    newNode->parent = NULL ;
    newNode->left = NULL ;
    newNode->right = NULL ;
    return newNode ;
}

/**** Add Left Child ****/
void bst:: addLeftChild(node* parent,node* child){
    parent->left = child ;

    if(child != NULL)
        child->parent = parent ;
}

/**** Add Right Child ****/
void bst:: addRightChild(node* parent,node* child){
    parent->right = child ;

    if(child != NULL)
        child->parent = parent ;
}

/**** Insert Node ****/
void bst:: insertNode(int data){
    node* newNode = createNode(data) ;
    if(root == NULL){
      /***
            if root is null, its mean the tree has no node yet.
            so if we add newNode then this is the only node the
            tree has. then it will be root node of the tree.
      ***/
        root = newNode ;
        return ;
    }

      node* currentNode = root ;
      node* parentNode = NULL ;
      /***
            Then we will find the parent node of newNode->data
            through a while loop.
      ***/
      while(currentNode != NULL){
        parentNode = currentNode ;

        if(newNode->data < currentNode->data)
            currentNode = currentNode->left ;
        else
            currentNode = currentNode->right ;
    }

    if(newNode->data < parentNode->data)
        addLeftChild(parentNode,newNode) ;
    else
        addRightChild(parentNode,newNode) ;
}

/**** In-Order Traversal ****/
void bst:: inOrder(node* currentNode){
    if(currentNode->left != NULL)
        inOrder(currentNode->left) ;

    // cout<< currentNode->data << " " ;
    sortedArray[pt++] = currentNode->data ;

    if(currentNode->right != NULL)
        inOrder(currentNode->right) ;
}

/**** Pre-order Traversal ****/
void bst:: pre_order(Node* node)
{
    printf("%d ", node->data);

    if(node->left) pre_order(node->left);
    if(node->right) pre_order(node->right);
}

/**** Post-Order Traversal ****/
void bst:: post_order(Node* node)
{
    if(node->left) post_order(node->left);
    if(node->right) post_order(node->right);

    printf("%d ", node->data);
}

/*** Search data ****/
bool bst:: isFound(int data){
    node* currentNode = root ;

    while(currentNode != NULL){
        if(currentNode->data == data)
            return true ;
        else if(data < currentNode->data)
            currentNode = currentNode->left ;
        else
            currentNode = currentNode->right ;
    }

    return false ;
}