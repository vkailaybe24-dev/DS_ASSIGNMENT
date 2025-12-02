#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev, *next;
};
Node* head = NULL;
void insertBeg(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL) head->prev = newNode;
    head = newNode;
}
void insertEnd(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void insertAfter(int val, int key){
    Node* temp = head;
    while(temp != NULL && temp->data != key) temp = temp->next;
    if(temp == NULL) return;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}
void deleteNode(int key){
    Node* temp = head;
    while(temp != NULL && temp->data != key) temp = temp->next;
    if(temp == NULL) return;
    if(temp == head) head = temp->next;
    if(temp->next != NULL) temp->next->prev = temp->prev;
    if(temp->prev != NULL) temp->prev->next = temp->next;
    delete temp;
}
void search(int key){
    Node* temp = head;
    int pos = 1;
    while(temp != NULL){
        if(temp->data == key){
            cout<<"Found at "<<pos<<endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout<<"Not Found"<<endl;
}
void display(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    int ch, val, k;
    while(1){
        cout<<"\n1.InsBeg 2.InsEnd 3.InsAfter 4.Del 5.Search 6.Disp 7.Exit: ";
        cin>>ch;
        switch(ch){
            case 1: cin>>val; insertBeg(val); break;
            case 2: cin>>val; insertEnd(val); break;
            case 3: cin>>val>>k; insertAfter(val, k); break;
            case 4: cin>>k; deleteNode(k); break;
            case 5: cin>>k; search(k); break;
            case 6: display(); break;
            case 7: return 0;
        }
    }

