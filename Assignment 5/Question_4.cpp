#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void reverse(Node** head_ref){
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void printList(Node* node){
    while (node != NULL) {
        cout << node->data;
        if(node->next) cout<<"->";
        else cout<<"->NULL";
        node = node->next;
    }
    cout << endl;
}
int main(){
    Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    cout << "Input: ";
    printList(head);
    reverse(&head);
    cout << "Output: ";
    printList(head);
    return 0;
}
