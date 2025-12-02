#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
bool isCircular(Node* head){
    if(head == NULL) return true;
    Node* temp = head->next;
    while(temp != NULL && temp != head) temp = temp->next;
    return (temp == head);
}
int main(){
    Node* head = new Node();
    head->next = new Node();
    head->next->next = head;
    if(isCircular(head)) cout<<"Circular Linked List"<<endl;
    else cout<<"Not Circular"<<endl;
    return 0;
}
