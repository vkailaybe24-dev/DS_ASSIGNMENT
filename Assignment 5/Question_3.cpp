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
void printMiddle(Node *head){
    Node *slow_ptr = head;
    Node *fast_ptr = head;
    if (head!=NULL){
        while (fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        cout << "Middle Element: " << slow_ptr->data << endl;
    }
}
void printList(Node* node){
    while(node != NULL){
        cout<<node->data;
        if(node->next) cout<<"->";
        node = node->next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    cout<<"Input: ";
    printList(head);
    printMiddle(head);
    return 0;
}
