#include<iostream>
using namespace std;
struct Node{
    char data;
    Node *next, *prev;
};
void push(Node** head, char val){
    Node* newInfo = new Node();
    newInfo->data = val;
    newInfo->next = *head;
    newInfo->prev = NULL;
    if(*head != NULL) (*head)->prev = newInfo;
    *head = newInfo;
}
bool check(Node* head){
    if(head == NULL) return true;
    Node* r = head;
    while(r->next != NULL) r = r->next;
    Node* l = head;
    while(l != r && l->prev != r){
        if(l->data != r->data) return false;
        l = l->next; r = r->prev;
    }
    return true;
}
int main(){
    Node* head = NULL;
    push(&head, 'l'); push(&head, 'e'); push(&head, 'v'); push(&head, 'e'); push(&head, 'l');
    if(check(head)) cout<<"True"<<endl; else cout<<"False"<<endl;
    return 0;
}
