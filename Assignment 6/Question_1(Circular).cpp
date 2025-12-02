#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
void insertBeg(int val){
    Node* newNode = new Node();
    newNode->data = val;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}
void insertEnd(int val){
    Node* newNode = new Node();
    newNode->data = val;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}
void deleteNode(int key){
    if(head == NULL) return;
    if(head->data == key && head->next == head){
        delete head; head = NULL; return;
    }
    Node *temp = head, *prev = NULL;
    if(head->data == key){
        while(temp->next != head) temp = temp->next;
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }
    while(temp->next != head && temp->data != key){
        prev = temp; temp = temp->next;
    }
    if(temp->data == key){
        prev->next = temp->next;
        delete temp;
    }
}
void search(int key){
    if(head == NULL) return;
    Node* temp = head;
    int pos = 1;
    do{
        if(temp->data == key){
            cout<<"Found at "<<pos<<endl;
            return;
        }
        temp = temp->next;
        pos++;
    }while(temp != head);
    cout<<"Not Found"<<endl;
}
void display(){
    if(head == NULL) return;
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}
int main(){
    int ch, val, k;
    while(1){
        cout<<"\n1.InsBeg 2.InsEnd 3.Del 4.Search 5.Disp 6.Exit: ";
        cin>>ch;
        switch(ch){
            case 1: cin>>val; insertBeg(val); break;
            case 2: cin>>val; insertEnd(val); break;
            case 3: cin>>k; deleteNode(k); break;
            case 4: cin>>k; search(k); break;
            case 5: display(); break;
            case 6: return 0;
        }
    }
}
