#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void push(Node** head, int val){
    Node* newNode = new Node();
    newNode->data = val;
    if(*head == NULL){
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while(temp->next != *head) temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}
void display(Node* head){
    if(head == NULL) return;
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<head->data<<endl;
}
int main(){
    Node* head = NULL;
    push(&head, 60);
    push(&head, 80);
    push(&head, 40);
    push(&head, 100);
    push(&head, 20);
    display(head);
    return 0;
}
