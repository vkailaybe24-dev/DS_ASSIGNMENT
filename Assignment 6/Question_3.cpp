#include<iostream>
using namespace std;
struct DNode{ int data; DNode *next, *prev; };
struct CNode{ int data; CNode *next; };
int sizeDouble(DNode* head){
    int c = 0;
    while(head){ c++; head = head->next; }
    return c;
}
int sizeCircular(CNode* head){
    if(!head) return 0;
    int c = 0;
    CNode* t = head;
    do{ c++; t = t->next; }while(t!=head);
    return c;
}
int main(){
    DNode* d = new DNode(); d->next = new DNode(); d->next->next = NULL;
    CNode* c = new CNode(); c->next = new CNode(); c->next->next = c;
    cout<<"Doubly Size: "<<sizeDouble(d)<<endl;
    cout<<"Circular Size: "<<sizeCircular(c)<<endl;
    return 0;
}
