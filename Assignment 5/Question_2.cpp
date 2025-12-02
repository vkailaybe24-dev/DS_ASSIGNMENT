#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node* node){
    while (node != NULL){
        cout << node->data;
        if(node->next != NULL) cout << "->";
        node = node->next;
    }
    cout<<endl;
}
int countKey(Node* head, int key){
    int count = 0;
    Node* current = head;
    while (current != NULL){
        if (current->data == key)
            count++;
        current = current->next;
    }
    return count;
}
void deleteKey(Node** head_ref, int key){
    Node* temp = *head_ref;
    Node* prev = NULL;
    while (temp != NULL && temp->data == key){
        *head_ref = temp->next;
        delete temp;
        temp = *head_ref;
    }
    while (temp != NULL){
        while (temp != NULL && temp->data != key){
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return;
        prev->next = temp->next;
        delete temp;
        temp = prev->next;
    }
}
int main(){
    Node* head = NULL;
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1); 
    int key = 1;
    cout<<"Input Linked List: ";
    printList(head);
    cout<<"Key: "<<key<<endl;
    int c = countKey(head, key);
    cout << "Count: " << c << endl;
    deleteKey(&head, key);
    cout << "Updated Linked List: ";
    printList(head);
    return 0;
}
