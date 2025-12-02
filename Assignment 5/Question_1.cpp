#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node* head = NULL;
void insertBeg(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}
void insertEnd(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void insertBefore(int val, int key){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->data == key){
        insertBeg(val);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL && temp->next->data != key){
        temp = temp->next;
    }
    if(temp->next == NULL){
        cout<<"Node not found"<<endl;
    } else {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void insertAfter(int val, int key){
    Node* temp = head;
    while(temp != NULL && temp->data != key){
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"Node not found"<<endl;
    } else {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void deleteBeg(){
    if(head == NULL){
        cout<<"List is empty"<<endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
void deleteEnd(){
    if(head == NULL){
        cout<<"List is empty"<<endl;
    } else if(head->next == NULL){
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
}
void deleteSpecific(int key){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->data == key){
        deleteBeg();
        return;
    }
    Node* temp = head;
    while(temp->next != NULL && temp->next->data != key){
        temp = temp->next;
    }
    if(temp->next == NULL){
        cout<<"Node not found"<<endl;
    } else {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}
void searchNode(int key){
    int pos = 1;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            cout<<"Node found at position: "<<pos<<endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout<<"Node not found"<<endl;
}
void display(){
    Node* temp = head;
    if(temp == NULL) cout<<"List is empty";
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int ch, val, key, sub;
    while(1){
        cout<<"\n1.Insert Beg 2.Insert End 3.Insert Between 4.Delete Beg 5.Delete End 6.Delete Specific 7.Search 8.Display 9.Exit\nEnter choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter value: "; cin>>val; insertBeg(val); break;
            case 2: cout<<"Enter value: "; cin>>val; insertEnd(val); break;
            case 3: 
                cout<<"1.Before Node 2.After Node: "; cin>>sub;
                cout<<"Enter value to insert: "; cin>>val;
                cout<<"Enter specific node value: "; cin>>key;
                if(sub==1) insertBefore(val, key); else insertAfter(val, key);
                break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: cout<<"Enter node to delete: "; cin>>key; deleteSpecific(key); break;
            case 7: cout<<"Enter node to search: "; cin>>key; searchNode(key); break;
            case 8: display(); break;
            case 9: return 0;
            default: cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
