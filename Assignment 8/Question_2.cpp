#include<iostream>
using namespace std;
struct Node{
    int key;
    Node *left, *right;
};
Node* newNode(int item){
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
Node* insert(Node* node, int key){
    if(node == NULL) return newNode(key);
    if(key < node->key) node->left = insert(node->left, key);
    else if(key > node->key) node->right = insert(node->right, key);
    return node;
}
bool searchRec(Node* root, int key){
    if(root == NULL) return false;
    if(root->key == key) return true;
    if(root->key < key) return searchRec(root->right, key);
    return searchRec(root->left, key);
}
bool searchNonRec(Node* root, int key){
    while(root != NULL){
        if(key > root->key) root = root->right;
        else if(key < root->key) root = root->left;
        else return true;
    }
    return false;
}
int findMax(Node* root){
    if(root == NULL) return -1;
    while(root->right != NULL) root = root->right;
    return root->key;
}
int findMin(Node* root){
    if(root == NULL) return -1;
    while(root->left != NULL) root = root->left;
    return root->key;
}
Node* findSucc(Node* root, Node* n){
    if(n->right != NULL){
        Node* curr = n->right;
        while(curr->left != NULL) curr = curr->left;
        return curr;
    }
    Node* succ = NULL;
    while(root != NULL){
        if(n->key < root->key){
            succ = root;
            root = root->left;
        } else if(n->key > root->key) root = root->right;
        else break;
    }
    return succ;
}
Node* findPred(Node* root, Node* n){
    if(n->left != NULL){
        Node* curr = n->left;
        while(curr->right != NULL) curr = curr->right;
        return curr;
    }
    Node* pred = NULL;
    while(root != NULL){
        if(n->key > root->key){
            pred = root;
            root = root->right;
        } else if(n->key < root->key) root = root->left;
        else break;
    }
    return pred;
}
Node* getKeyNode(Node* root, int key){
    while(root!=NULL){
        if(key>root->key) root=root->right;
        else if(key<root->key) root=root->left;
        else return root;
    }
    return NULL;
}
int main(){
    Node* root = NULL;
    root = insert(root, 50); insert(root, 30); insert(root, 20);
    insert(root, 40); insert(root, 70); insert(root, 60); insert(root, 80);
    cout<<"Max: "<<findMax(root)<<endl;
    cout<<"Min: "<<findMin(root)<<endl;
    Node* target = getKeyNode(root, 60);
    if(target){
        Node* s = findSucc(root, target);
        if(s) cout<<"Succ of 60: "<<s->key<<endl;
        Node* p = findPred(root, target);
        if(p) cout<<"Pred of 60: "<<p->key<<endl;
    }
    return 0;
}
