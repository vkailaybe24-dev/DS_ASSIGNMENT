#include<iostream>
#include<algorithm>
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
    if(key == node->key) return node;
    if(key < node->key) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);
    return node;
}
Node* minValueNode(Node* node){
    Node* current = node;
    while(current && current->left != NULL) current = current->left;
    return current;
}
Node* deleteNode(Node* root, int key){
    if(root == NULL) return root;
    if(key < root->key) root->left = deleteNode(root->left, key);
    else if(key > root->key) root->right = deleteNode(root->right, key);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int maxDepth(Node* node){
    if(node == NULL) return 0;
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    return max(lDepth, rDepth) + 1;
}
int minDepth(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    if(!root->left) return minDepth(root->right) + 1;
    if(!root->right) return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
int main(){
    Node* root = NULL;
    root = insert(root, 50); root = insert(root, 30); root = insert(root, 20);
    root = insert(root, 40); root = insert(root, 70); root = insert(root, 60);
    cout<<"Max Depth: "<<maxDepth(root)<<endl;
    cout<<"Min Depth: "<<minDepth(root)<<endl;
    root = deleteNode(root, 20);
    cout<<"After deleting 20, Max Depth: "<<maxDepth(root)<<endl;
    return 0;
}
