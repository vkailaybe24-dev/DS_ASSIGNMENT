#include<iostream>
#include<unordered_set>
using namespace std;
struct Node{
    int data;
    Node* next;
};
bool hasCycle(Node* head){
    unordered_set<Node*> s;
    while(head != NULL){
        if(s.find(head) != s.end()) return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}
int main(){
    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};
    head->next->next->next->next = head->next;
    if(hasCycle(head)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
