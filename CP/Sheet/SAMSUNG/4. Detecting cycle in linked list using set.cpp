
#include<iostream>
#include<unordered_set>
using namespace std;
struct node{
    int data;
    node *next;
};

void addNode(node **head, int data){
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    if(*head==NULL) *head = temp;
    else{
        node *tail = *head;
        while(tail->next!=NULL) tail = tail->next;
        tail->next = temp;
    }
}
bool hasCycle(node *head){
    unordered_set<node*> st;

    struct node *temp = new node();
    temp = head;
    while(temp != NULL) {
        if(st.find(temp) != st.end()) return true;
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    node *head = NULL;
    int n, x;
    cin>>n;
    while(n--){
        cin>>x;
        addNode(&head, x);
    }
    //create a loop
    node *temp = head;
    while(temp->data!=x) temp = temp->next;
    temp->next = head;

    //printList(head);
    cout<<hasCycle(head)<<endl;
}
