/***
    solution: Time complexity and space complexity O(n)
***/

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void addNode(struct node **head, int data){
    node *temp = new node();
    temp->data = data ;
    temp->next = NULL;

    if(*head == NULL) *head = temp;
    else {
        struct node *tail ;
        tail = *head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = temp; /// adding new node
    }
}


bool hasCycle(struct node* head){
    node *slow = head, *fast = head;

    while(slow && fast && fast->next) {
        slow = slow->next ;
        fast = fast->next->next;

        if(slow == fast) return true; /// detecting cycle here
    }
    return false; /// no cycle here
}

void printList(struct node* head){
    node* temp = new node();
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    struct node *head = NULL;
    int n, x;
    cin>>n;
    while(n--){
        cin>>x;
        addNode(&head, x);
    }
    ///create a loop
    struct node *temp = head;
    while(temp->data != x) temp = temp->next;
    temp->next = head;

    ///printList(head);
    cout<<hasCycle(head)<<endl;
}

